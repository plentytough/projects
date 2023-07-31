		//---------------------------------------------------------------------------

		#include <vcl.h>
		#pragma hdrstop
		#include <stdio.h>
		#include <string>
		#include <string.h>
		#include <vector>
		#include <iostream>
		#include <fstream>
		#include <cstdlib>
		#include <regex>
		#include <algorithm>
		#include "Unit1.h"

		using namespace std;

		static int NUMBER = 1;                                      //回答回数カウンター
		static int temp   = 0;

		static string convertedUnicodeString = "";                 //UnicodeStringからstring型に変換して格納
																   //C++各種関数利用のため

		static UnicodeString LINE  = "";                            //Edit1入力格納用UnicodeStringグローバル変数
		static UnicodeString TEXT_PREV = " ";                       //１つ前の入力格納用UnicodeStringグローバル変数

		static UnicodeString dbString = "";                         //ﾃﾞｰﾀﾍﾞｰｽから取得用文字列
		static vector<string> dictionary(106332);                  //辞書ファイルデータ格納用可変長配列
		static vector<string> ansWords(20);     					//入力単語格納用可変長配列
		static String DataBase = "localhost:C:/Users/Public/Documents/Embarcadero/Studio/20.0/Samples/Data/DB1.IB";

		//---------------------------------------------------------------------------
		#pragma package(smart_init)
		#pragma resource "*.dfm"
		TForm1 *Form1;

		//---------------------------------------------------------------------------

		int checkWord(UnicodeString str) {                          //入力チェック関数
		int n = 0;
		int length = convertedUnicodeString.length();
		string temp (((AnsiString)str).c_str());
		string startstr = temp.substr(0,1);
		string temp_prev (((AnsiString)TEXT_PREV).c_str());
		string end_prev = temp_prev.substr(temp_prev.length()-1);

		if(NUMBER==1&&startstr!="A") return 5;                        //始まりがAでない場合の処理

		if(length==0){return 4;}                                      //無入力時の処理

		if(!regex_match(convertedUnicodeString, regex("^[A-Z]+$"))){  //入力が(A～Z)かを判定する処理
		return 3;}

		if(NUMBER>1&&end_prev!=startstr)return 9;                      //しりとり不成立時の処理

		if(length<3) return 2;

		//辞書検索して単語がない場合の処理
		if(find(dictionary.begin(), dictionary.end(), convertedUnicodeString)==dictionary.end())return 6;

		//既に入力された単語と一致するか検索
		if(find(ansWords.begin(), ansWords.end(), convertedUnicodeString)!=ansWords.end())return 7;

		return 0;

		}

		//---------------------------------------------------------------------------

		UnicodeString showResult(int i){
			   UnicodeString result="";                                  //ゲーム終了時の結果表示
			   switch(i){
				case 1: result = "  あなたの負けです ";break;
				case 2: result = "  単語が短すぎます ";break;
				case 3: result = "    ｱﾙﾌｧﾍﾞｯﾄ　のみ   ";break;
				case 4: result = "何も入力されていません";break;
				case 5: result = "　最初はA(a)からです ";break;
				case 6: result = " 辞書にありません ";break;
				case 7: result = " すでに使われた単語です ";break;
				case 8: result = " ｼｽﾃﾑｴﾗｰ ";break;
				case 9: result = " しりとり不成立 ";break;
				case 10: result = " ﾃｽﾄ ";break;
				default: break;
				}
				return result;

		}

		//---------------------------------------------------------------------------
		__fastcall TForm1::TForm1(TComponent* Owner)
			: TForm(Owner)
		{

		}
		//---------------------------------------------------------------------------

		void __fastcall TForm1::Button2Click(TObject *Sender)
		{
		FDQuery1->SQL->Text = "DELETE FROM WORDS";
		FDQuery1->ExecSQL();
		FDQuery1->Close();
		Close();
		}
		//---------------------------------------------------------------------------

		void __fastcall TForm1::Button1Click(TObject *Sender)
		{                                                               //Send Answer の処理


		int i=0,n=0,x=0;
		x=(20-NUMBER)/2;
		if(NUMBER>1)TEXT_PREV = LINE;
		UnicodeString str = Edit1->Text.UpperCase();
		UnicodeString result = "";
		string temp (((AnsiString)str).c_str());
		convertedUnicodeString = temp;

		if(str.Length()>20)	LINE = str.SubString(0,20);
		else LINE = str;

		n = checkWord(str);

		if(n==0){

		ansWords.push_back(convertedUnicodeString);

		if(NUMBER%2==1){


		switch(x){
																		 //表示をずらす(先手用)
		case 0:
		Label10->Caption = Label9->Caption;
		case 1:
		if(x==1)Label10->Caption = "残り    "+IntToStr(x);
		Label9->Caption = Label8->Caption;
		case 2:
		if(x==2)Label9->Caption = "残り    "+IntToStr(x);
		Label8->Caption = Label7->Caption;
		case 3:
		if(x==3)Label8->Caption = "残り    "+IntToStr(x);
		Label7->Caption = Label6->Caption;
		case 4:
		if(x==4)Label7->Caption = "残り    "+IntToStr(x);
		Label6->Caption = Label5->Caption;
		case 5:
		if(x==5)Label6->Caption = "残り    "+IntToStr(x);
		Label5->Caption = Label4->Caption;
		case 6:
		if(x==6)Label5->Caption = "残り    "+IntToStr(x);
		Label4->Caption = Label3->Caption;
		case 7:
		if(x==7)Label4->Caption = "残り    "+IntToStr(x);
		Label3->Caption = Label2->Caption;
		case 8:
		if(x==8)Label3->Caption = "残り    "+IntToStr(x);
		Label2->Caption = Label1->Caption;
		case 9:
		if(x==9)Label2->Caption = "残り    "+IntToStr(x);
		Label1->Caption = str;
		Edit1->Text = ""; break;

		default:
		break;
				}

			}
		}


		if(NUMBER%2==0){

																			 //表示をずらす(後手用)
		switch(x){

		case 0:
		Label20->Caption = Label19->Caption;
		case 1:
		if(x==1)Label20->Caption = "残り    "+IntToStr(x);
		Label19->Caption = Label18->Caption;
		case 2:
		if(x==2)Label19->Caption = "残り    "+IntToStr(x);
		Label18->Caption = Label17->Caption;
		case 3:
		if(x==3)Label18->Caption = "残り    "+IntToStr(x);
		Label17->Caption = Label16->Caption;
		case 4:
		if(x==4)Label17->Caption = "残り    "+IntToStr(x);
		Label16->Caption = Label15->Caption;
		case 5:
		if(x==5)Label16->Caption = "残り    "+IntToStr(x);
		Label15->Caption = Label14->Caption;
		case 6:
		if(x==6)Label15->Caption = "残り    "+IntToStr(x);
		Label14->Caption = Label13->Caption;
		case 7:
		if(x==7)Label14->Caption = "残り    "+IntToStr(x);
		Label13->Caption = Label12->Caption;
		case 8:
		if(x==8)Label13->Caption = "残り    "+IntToStr(x);
		Label12->Caption = Label11->Caption;
		case 9:
		if(x==9)Label12->Caption = "残り    "+IntToStr(x);
		Label11->Caption = str;
		Edit1->Text = ""; break;

		default:
		break;
			}


		}

		//負けた場合の表示とリセット処理											　　　
		if(n!=0){
		result = showResult(n);
		Edit1->Text = result;
		Button1->Visible = false;
		Button3->Visible = true;
		NUMBER = 1;

		}

		try{
		FDQuery1->SQL->Text = "INSERT INTO WORDS VALUES (:NUMBER, :WORD, :PLAYER)";
		FDQuery1->ParamByName("NUMBER")->AsInteger = NUMBER;
		FDQuery1->ParamByName("WORD")->AsString = LINE;
        FDQuery1->ParamByName("PLAYER")->AsString = "C++";
		FDQuery1->ExecSQL();
		  }
		catch(Exception &ep){
		Edit1->Text = "ｴﾗｰ";}

		NUMBER++;
																 //20回正常終了時
		if(NUMBER==21){
		Edit1->Text = "引き分けです";
		Button1->Visible =false;
		Button3->Visible = true;
		NUMBER = 1;
		LINE = "";
		TEXT_PREV = " ";
		ansWords.clear();

		}

		}
		//---------------------------------------------------------------------------


		void __fastcall TForm1::Button3Click(TObject *Sender)
		{
		int x=0;                                                          //retryボタンのｱｸｼｮﾝｲﾍﾞﾝﾄ

		Button3->Visible = false;
		Button1->Visible = true;
		Edit1->Text = "";
		NUMBER=1;
		LINE = "";
		TEXT_PREV = " ";
		ansWords.clear();

		x=(21-NUMBER)/2;

		Label1->Caption  =  "残り   "+IntToStr(x);
		Label2->Caption  =  "？ ？ ？";
		Label3->Caption  =  "？ ？ ？";
		Label4->Caption  =  "？ ？ ？";
		Label5->Caption  =  "？ ？ ？";
		Label6->Caption  =  "？ ？ ？";
		Label7->Caption  =  "？ ？ ？";
		Label8->Caption  =  "？ ？ ？";
		Label9->Caption  =  "？ ？ ？";
		Label10->Caption =  "？ ？ ？";
		Label11->Caption =  "残り   "+IntToStr(x);
		Label12->Caption =  "？ ？ ？";
		Label13->Caption =  "？ ？ ？";
		Label14->Caption =  "？ ？ ？";
		Label15->Caption =  "？ ？ ？";
		Label16->Caption =  "？ ？ ？";
		Label17->Caption =  "？ ？ ？";
		Label18->Caption =  "？ ？ ？";
		Label19->Caption =  "？ ？ ？";
		Label20->Caption =  "？ ？ ？";

		}
		//---------------------------------------------------------------------------




		void __fastcall TForm1::FormCreate(TObject *Sender)
		{

		FDConnection1->Params->Database =  DataBase;
		int x=0;                                                 //初期画面設定と辞書ファイルの読み込み
		x=(21-NUMBER)/2;

		Label1->Caption  =  "残り   "+IntToStr(x);
		Label2->Caption  =  "？ ？ ？";
		Label3->Caption  =  "？ ？ ？";
		Label4->Caption  =  "？ ？ ？";
		Label5->Caption  =  "？ ？ ？";
		Label6->Caption  =  "？ ？ ？";
		Label7->Caption  =  "？ ？ ？";
		Label8->Caption  =  "？ ？ ？";
		Label9->Caption  =  "？ ？ ？";
		Label10->Caption =  "？ ？ ？";
		Label11->Caption =  "残り   "+IntToStr(x);
		Label12->Caption =  "？ ？ ？";
		Label13->Caption =  "？ ？ ？";
		Label14->Caption =  "？ ？ ？";
		Label15->Caption =  "？ ？ ？";
		Label16->Caption =  "？ ？ ？";
		Label17->Caption =  "？ ？ ？";
		Label18->Caption =  "？ ？ ？";
		Label19->Caption =  "？ ？ ？";
		Label20->Caption =  "？ ？ ？";

		string filetext = "";
		ifstream ifs("C:/Shiritori Files/EnglishDictionary.txt");

		if(! ifs){
		Edit1->Text=" ｼｽﾃﾑｴﾗｰ ";
		Button1->Visible=false;
		Button3->Visible=true;
		}

		while(getline(ifs,filetext)){
		dictionary.push_back(filetext);

		if(! ifs){
		Edit1->Text=" ｼｽﾃﾑｴﾗｰ ";
		Button1->Visible=false;
		Button3->Visible=true;
				}
			}

		}
		//---------------------------------------------------------------------------

