using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using static System.Runtime.InteropServices.JavaScript.JSType;


namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 
    public partial class MainWindow : Window
    {
        static int NUMBER = 1;                                      //回答回数カウンター
           
        static string LINE = "";                                   //TextBox入力格納用stringグローバル変数
        static string TEXT_PREV = " ";                              //１つ前の入力格納用stringグローバル変数
        static string dicLine = "";                                 //辞書ファイル読込用stringグローバル変数

        static List<string> dictionary = new List<string>();                           //辞書ファイルデータ格納用可変長配列
        static List<string> ansWords = new List<string>();                            //入力単語格納用可変長配列





        int checkWord(string str)
        {                                                                             //入力チェック関数
            string startstr = str.Substring(0, 1);
            string end_prev = TEXT_PREV.Substring(TEXT_PREV.Length-1);


            if (NUMBER == 1 && startstr != "A") return 5;                        //始まりがAでない場合の処理

            if (str.Length == 0) { return 4; }                                      //無入力時の処理

            if (!Regex.IsMatch(str, ("^[A-Z]+$")))
            {                                                                       //入力が(A～Z)かを判定する処理
                return 3;
            }

            if (NUMBER > 1 && end_prev != startstr) return 9;                      //しりとり不成立時の処理

            if (str.Length < 3) return 2;

            //辞書検索して単語がない場合の処理
            if (!dictionary.Contains(str)) return 6;

            //既に入力された単語と一致するか検索
            if (ansWords.Contains(str)) return 7;
            return 0;
        }
        string showResult(int i)
        {
            string result = "";                                                       //ゲーム終了時の結果表示
            switch (i)
            {
                case 1: result = "  あなたの負けです "; break;
                case 2: result = "  単語が短すぎます "; break;
                case 3: result = "    ｱﾙﾌｧﾍﾞｯﾄ　のみ   "; break;
                case 4: result = "何も入力されていません"; break;
                case 5: result = "　最初はA(a)からです "; break;
                case 6: result = " 辞書にありません "; break;
                case 7: result = " すでに使われた単語です "; break;
                case 8: result = " ｼｽﾃﾑｴﾗｰ "; break;
                case 9: result = " しりとり不成立 "; break;
                case 10: result = " ﾃｽﾄ "; break;
                default: break;
            }
            return result;

        }


        public MainWindow()
        {
            InitializeComponent();
            Button3.IsEnabled = false;

            int x = (21 - NUMBER) / 2;
            Label1.Content = "残り   " + x;
            Label2.Content = "？ ？ ？";
            Label3.Content = "？ ？ ？";
            Label4.Content = "？ ？ ？";
            Label5.Content = "？ ？ ？";
            Label6.Content = "？ ？ ？";
            Label7.Content = "？ ？ ？";
            Label8.Content = "？ ？ ？";
            Label9.Content = "？ ？ ？";
            Label10.Content = "？ ？ ？";
            Label11.Content = "残り   " + x;
            Label12.Content = "？ ？ ？";
            Label13.Content = "？ ？ ？";
            Label14.Content = "？ ？ ？";
            Label15.Content = "？ ？ ？";
            Label16.Content = "？ ？ ？";
            Label17.Content = "？ ？ ？";
            Label18.Content = "？ ？ ？";
            Label19.Content = "？ ？ ？";
            Label20.Content = "？ ？ ？";

            StreamReader SR = new StreamReader("C:\\Shiritori Files\\EnglishDictionary.txt");

            while (SR.EndOfStream == false) { dicLine = SR.ReadLine(); dictionary.Add(dicLine); }
            SR.Close();
        }

        private void Button1_Click(object sender, RoutedEventArgs e)
        {
            int n = 0, x = 0;
            x = (20 - NUMBER) / 2;
            if (NUMBER > 1) TEXT_PREV = LINE;
            string str = TextBox1.Text.ToUpper();
            string result = "";

            if (str.Length > 20) LINE = str.Substring(0, 20);
            else LINE = str;

            n = checkWord(LINE);

            if (n == 0)
            {

                ansWords.Add(str);

                if (NUMBER % 2 == 1)
                {


                    switch (x)
                    {
                        //表示をずらす(先手用)
                        case 0:
                            { Label10.Content = Label9.Content; goto NEXT_1; }

                        case 1:
                        NEXT_1:
                            if (x == 1) Label10.Content = "残り    " + x;
                            { Label9.Content = Label8.Content; goto NEXT_2; }
                        case 2:
                        NEXT_2:
                            if (x == 2) Label9.Content = "残り    " + x;
                            { Label8.Content = Label7.Content; goto NEXT_3; }
                        case 3:
                        NEXT_3:
                            if (x == 3) Label8.Content = "残り    " + x;
                            { Label7.Content = Label6.Content; goto NEXT_4; }
                        case 4:
                        NEXT_4:
                            if (x == 4) Label7.Content = "残り    " + x;
                            { Label6.Content = Label5.Content; goto NEXT_5; }
                        case 5:
                        NEXT_5:
                            if (x == 5) Label6.Content = "残り    " + x;
                            { Label5.Content = Label4.Content; goto NEXT_6; }
                        case 6:
                        NEXT_6:
                            if (x == 6) Label5.Content = "残り    " + x;
                            { Label4.Content = Label3.Content; goto NEXT_7; }
                        case 7:
                        NEXT_7:
                            if (x == 7) Label4.Content = "残り    " + x;
                            { Label3.Content = Label2.Content; goto NEXT_8; }
                        case 8:
                        NEXT_8:
                            if (x == 8) Label3.Content = "残り    " + x;
                            { Label2.Content = Label1.Content; goto NEXT_9; }
                        case 9:
                        NEXT_9:
                            if (x == 9) Label2.Content = "残り    " + x;
                            { Label1.Content = LINE; TextBox1.Text = ""; break; }

                        default:
                            break;
                    }

                }



                if (NUMBER % 2 == 0)
                {

                    //表示をずらす(後手用)
                    switch (x)
                    {

                        case 0:
                            { Label20.Content = Label19.Content; goto NEXT_11; }
                        case 1:
                        NEXT_11:
                            if (x == 1) Label20.Content = "残り    " + x;
                            { Label19.Content = Label18.Content; goto NEXT_12; }
                        case 2:
                        NEXT_12:
                            if (x == 2) Label19.Content = "残り    " + x;
                            { Label18.Content = Label17.Content; goto NEXT_13; }
                        case 3:
                        NEXT_13:
                            if (x == 3) Label18.Content = "残り    " + x;
                            { Label17.Content = Label16.Content; goto NEXT_14; }
                        case 4:
                        NEXT_14:
                            if (x == 4) Label17.Content = "残り    " + x;
                            { Label16.Content = Label15.Content; goto NEXT_15; }
                        case 5:
                        NEXT_15:
                            if (x == 5) Label16.Content = "残り    " + x;
                            { Label15.Content = Label14.Content; goto NEXT_16; }
                        case 6:
                        NEXT_16:
                            if (x == 6) Label15.Content = "残り    " + x;
                            { Label14.Content = Label13.Content; goto NEXT_17; }
                        case 7:
                        NEXT_17:
                            if (x == 7) Label14.Content = "残り    " + x;
                            { Label13.Content = Label12.Content; goto NEXT_18; }
                        case 8:
                        NEXT_18:
                            if (x == 8) Label13.Content = "残り    " + x;
                            { Label12.Content = Label11.Content; goto NEXT_19; }
                        case 9:
                        NEXT_19:
                            if (x == 9) Label12.Content = "残り    " + x;
                            Label11.Content = LINE;
                            TextBox1.Text = ""; break;

                        default:
                            break;
                    }

                }
            }
            if (n != 0)
            {
                result = showResult(n);
                TextBox1.Text = result;
                Button1.Visibility = Visibility.Hidden;
                Button1.IsEnabled = false;
                Button3.Visibility = Visibility.Visible;
                Button3.IsEnabled = true;
                NUMBER = 1;

            }
            NUMBER++;

        
    }


        private void Button2_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void Button3_Click(object sender, RoutedEventArgs e)
        {
            NUMBER = 1;
            LINE = "";
            TEXT_PREV = " ";
            ansWords.Clear();
            TextBox1.Text = "";
            int x = (21 - NUMBER) / 2;
            Label1.Content = "残り   " + x;
            Label2.Content = "？ ？ ？";
            Label3.Content = "？ ？ ？";
            Label4.Content = "？ ？ ？";
            Label5.Content = "？ ？ ？";
            Label6.Content = "？ ？ ？";
            Label7.Content = "？ ？ ？";
            Label8.Content = "？ ？ ？";
            Label9.Content = "？ ？ ？";
            Label10.Content = "？ ？ ？";
            Label11.Content = "残り   " + x;
            Label12.Content = "？ ？ ？";
            Label13.Content = "？ ？ ？";
            Label14.Content = "？ ？ ？";
            Label15.Content = "？ ？ ？";
            Label16.Content = "？ ？ ？";
            Label17.Content = "？ ？ ？";
            Label18.Content = "？ ？ ？";
            Label19.Content = "？ ？ ？";
            Label20.Content = "？ ？ ？";

            Button3.Visibility = Visibility.Hidden;
            Button3.IsEnabled = false;
            Button1.Visibility = Visibility.Visible;
            Button1.IsEnabled = true;

        }
    }
}
