import java.awt.BorderLayout;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Iterator;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
//import java.sql.DriverManager;
//import java.sql.PreparedStatement;
//import java.sql.ResultSet;
//import java.sql.SQLException;
//import java.sql.Statement;


public class Shiritori_Windows {
	public static final int ALIGN_X = 150;			//各labelの座標決定基準値
	public static final int ALIGN_Y =  40;
	public static final int WIDTH    = 120;
	public static final int HEIGHT   = 40;
	public static final int MARGIN_X =  120;
	public static final int MARGIN_Y =  60;

	public static final int BUTTON_X  = 280;		//各Buttonの座標決定基準値
	public static final int BUTTON_Y  = 450;
	public static final int BUTTON_MARGIN_X = 150;
	public static final int BUTTON_MARGIN_Y = 0;
	public static final int BUTTON_WIDTH  = 130;
	public static final int BUTTON_HEIGHT =30;
	
//	public static Connection con;					//Database接続用変数のstatic宣言	(機能停止中)
//	public static PreparedStatement pps;
//	public static ResultSet rs;
//	public static Statement stm;
//  Statement stm = con.createStatement();
//	String sql ="";
//	stm.executeUpdate(sql);
//	pps = con.prepareStatement("");
//	rs = pps.executeQuery();
//	rs.beforeFirst();

	
	public static int NUMBER = 1;					//しりとりの回数カウント用変数
	public static int temp = 0;
	public static String TEXT = "";
	public static String limitedString = "";
	public static void main(String[] args) {

		ArrayList<String> ansWords = new ArrayList<String>	();		//回答格納用配列
		ArrayList<String> dictionary = new ArrayList<String>();		//辞書格納用配列
		
		int x = 0;
		x = (21-NUMBER)/2;
		JFrame frame =new JFrame("し　り　と　り    (Java Version)");						//オブジェクト生成
		JButton button1 = new JButton("Send Answer");
		JButton button2 = new JButton("Retry");
		JButton button3 = new JButton("Exit");
		JLabel label1   = new JLabel("残り   "+ x);
		JLabel label2   = new JLabel("？ ？ ？");
		JLabel label3   = new JLabel("？ ？ ？");
		JLabel label4   = new JLabel("？ ？ ？");
		JLabel label5   = new JLabel("？ ？ ？");
		JLabel label6   = new JLabel("？ ？ ？");
		JLabel label7   = new JLabel("？ ？ ？");
		JLabel label8   = new JLabel("？ ？ ？");
		JLabel label9   = new JLabel("？ ？ ？");
		JLabel label10  = new JLabel("？ ？ ？");
		JLabel label11  = new JLabel("残り   "+ x);
		JLabel label12  = new JLabel("？ ？ ？");
		JLabel label13  = new JLabel("？ ？ ？");
		JLabel label14  = new JLabel("？ ？ ？");
		JLabel label15  = new JLabel("？ ？ ？");
		JLabel label16  = new JLabel("？ ？ ？");
		JLabel label17  = new JLabel("？ ？ ？");
		JLabel label18  = new JLabel("？ ？ ？");
		JLabel label19  = new JLabel("？ ？ ？");
		JLabel label20  = new JLabel("？ ？ ？");
		JTextField textfield1 = new JTextField("");
	
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		// ﾃﾞﾌｫﾙﾄ指定解除
		frame.setSize(800,600);
		frame.setLocationRelativeTo(null);
		frame.setResizable(true);
		frame.add(button1,BorderLayout.CENTER);
		frame.add(button2,BorderLayout.CENTER);
		frame.add(button3,BorderLayout.CENTER);
		frame.add(label1,BorderLayout.CENTER);
		frame.add(label2,BorderLayout.CENTER);
		frame.add(label3,BorderLayout.CENTER);
		frame.add(label4,BorderLayout.CENTER);
		frame.add(label5,BorderLayout.CENTER);
		frame.add(label6,BorderLayout.CENTER);
		frame.add(label7,BorderLayout.CENTER);
		frame.add(label8,BorderLayout.CENTER);
		frame.add(label9,BorderLayout.CENTER);
		frame.add(label10,BorderLayout.CENTER);
		frame.add(label11,BorderLayout.CENTER);
		frame.add(label12,BorderLayout.CENTER);
		frame.add(label13,BorderLayout.CENTER);
		frame.add(label14,BorderLayout.CENTER);
		frame.add(label15,BorderLayout.CENTER);
		frame.add(label16,BorderLayout.CENTER);
		frame.add(label17,BorderLayout.CENTER);
		frame.add(label18,BorderLayout.CENTER);
		frame.add(label19,BorderLayout.CENTER);
		frame.add(label20,BorderLayout.CENTER);
		frame.add(textfield1,BorderLayout.CENTER);

		frame.setLayout(null);
		label1.setLayout(null);
		label2.setLayout(null);
		textfield1.setLayout(null);
		button1.setLayout(null);
		button2.setLayout(null);
		button3.setLayout(null);

		//各ﾊﾟｰﾂ配置

		label1.setBounds(ALIGN_X+(MARGIN_X)*0,ALIGN_Y+(MARGIN_Y)*0,WIDTH,HEIGHT);
		label2.setBounds(ALIGN_X+(MARGIN_X)*0,ALIGN_Y+(MARGIN_Y)*1,WIDTH,HEIGHT);
		label3.setBounds(ALIGN_X+(MARGIN_X)*0,ALIGN_Y+(MARGIN_Y)*2,WIDTH,HEIGHT);
		label4.setBounds(ALIGN_X+(MARGIN_X)*0,ALIGN_Y+(MARGIN_Y)*3,WIDTH,HEIGHT);
		label5.setBounds(ALIGN_X+(MARGIN_X)*0,ALIGN_Y+(MARGIN_Y)*4,WIDTH,HEIGHT);
		label6.setBounds(ALIGN_X+(MARGIN_X)*1,ALIGN_Y+(MARGIN_Y)*0,WIDTH,HEIGHT);
		label7.setBounds(ALIGN_X+(MARGIN_X)*1,ALIGN_Y+(MARGIN_Y)*1,WIDTH,HEIGHT);
		label8.setBounds(ALIGN_X+(MARGIN_X)*1,ALIGN_Y+(MARGIN_Y)*2,WIDTH,HEIGHT);
		label9.setBounds(ALIGN_X+(MARGIN_X)*1,ALIGN_Y+(MARGIN_Y)*3,WIDTH,HEIGHT);
		label10.setBounds(ALIGN_X+(MARGIN_X)*1,ALIGN_Y+(MARGIN_Y)*4,WIDTH,HEIGHT);
		label11.setBounds(ALIGN_X+(MARGIN_X)*4,ALIGN_Y+(MARGIN_Y)*0,WIDTH,HEIGHT);
		label12.setBounds(ALIGN_X+(MARGIN_X)*4,ALIGN_Y+(MARGIN_Y)*1,WIDTH,HEIGHT);
		label13.setBounds(ALIGN_X+(MARGIN_X)*4,ALIGN_Y+(MARGIN_Y)*2,WIDTH,HEIGHT);
		label14.setBounds(ALIGN_X+(MARGIN_X)*4,ALIGN_Y+(MARGIN_Y)*3,WIDTH,HEIGHT);
		label15.setBounds(ALIGN_X+(MARGIN_X)*4,ALIGN_Y+(MARGIN_Y)*4,WIDTH,HEIGHT);
		label16.setBounds(ALIGN_X+(MARGIN_X)*3,ALIGN_Y+(MARGIN_Y)*0,WIDTH,HEIGHT);
		label17.setBounds(ALIGN_X+(MARGIN_X)*3,ALIGN_Y+(MARGIN_Y)*1,WIDTH,HEIGHT);
		label18.setBounds(ALIGN_X+(MARGIN_X)*3,ALIGN_Y+(MARGIN_Y)*2,WIDTH,HEIGHT);
		label19.setBounds(ALIGN_X+(MARGIN_X)*3,ALIGN_Y+(MARGIN_Y)*3,WIDTH,HEIGHT);
		label20.setBounds(ALIGN_X+(MARGIN_X)*3,ALIGN_Y+(MARGIN_Y)*4,WIDTH,HEIGHT);

		button1.setBounds(BUTTON_X+(BUTTON_MARGIN_X)*0,BUTTON_Y+(BUTTON_MARGIN_Y)*0,BUTTON_WIDTH,BUTTON_HEIGHT);
		button2.setBounds(BUTTON_X+(BUTTON_MARGIN_X)*0,BUTTON_Y+(BUTTON_MARGIN_Y)*0,BUTTON_WIDTH,BUTTON_HEIGHT);
		button3.setBounds(BUTTON_X+(BUTTON_MARGIN_X)*1,BUTTON_Y+(BUTTON_MARGIN_Y)*0,BUTTON_WIDTH,BUTTON_HEIGHT);

		textfield1.setBounds(340,370,140,25);
		button2.setVisible(false);
		frame.setVisible(true);
		
		String filename =
				"C:/Shiritori Files/EnglishDictionary.txt";

		try {
			BufferedReader reader = new BufferedReader(new FileReader(filename),65535);
			String line;

			while ((line=reader.readLine()) != null) {
				dictionary.add(line.toUpperCase());					//辞書配列に格納
			}
			reader.close();
//		 	con = DriverManager.getConnection("jdbc:mariadb://localhost:3306/db3","root","1234");
//			Class.forName("interbase.interclient.Driver");
//			con = DriverManager.getConnection("jdbc:interbase://localhost:3050/C:/Users/Public/Documents/Embarcadero/Studio/20.0/Samples/Data/Db1.IB","SYSDBA","masterkey");

			}
		
		catch (FileNotFoundException fnf) {
			textfield1.setText("  ﾌｧｲﾙが見つかりません");
			button1.setVisible(false);
			button2.setVisible(true);
			
			//System.out.println("ファイルが見つかりません：" + fnf);
		} catch (IOException ioe) {
			textfield1.setText("  I/Oエラーです  ");
			button1.setVisible(false);
			button2.setVisible(true);
		}

//		catch(SQLException sqe) {
//			long ex= (long)sqe.getErrorCode();
//			textfield1.setText("SQLｴﾗｰ : "+ex);
//			button1.setVisible(false);
//			button2.setVisible(true);
//		}
		
//		catch(ClassNotFoundException cnfe) {
//			textfield1.setText("クラスが見つかりません");
//			button1.setVisible(false);
//			button2.setVisible(true);
//		}
		

		button1.addActionListener(e-> {
			int i = 0;
			int v = 0;
			v = (20-NUMBER)/2;
			String str = new String(textfield1.getText().toUpperCase());	//textfield内のtext格納・参照渡し用変数
			i = checkWords(str,ansWords,dictionary);
			if(i==0&&NUMBER%2==1) {
																			 //入力を一つずつずらす(先手用)
				switch(v) {
				
				case 0:
				label10.setText(label9.getText());
						
				case 1: 
				if(v==1)label10.setText("残り   "+ v);
				label9.setText(label8.getText());
				
				case 2:
				if(v==2)label9.setText("残り   "+ v);
				label8.setText(label7.getText());
				
				case 3:
				if(v==3)label8.setText("残り   "+ v);
				label7.setText(label6.getText());
				
				case 4:
				if(v==4)label7.setText("残り   "+ v);
				label6.setText(label5.getText());
				
				case 5:
				if(v==5)label6.setText("残り   "+ v);
				label5.setText(label4.getText());
				
				case 6:
				if(v==6)label5.setText("残り   "+ v);
				label4.setText(label3.getText());
				
				case 7:
				if(v==7)label4.setText("残り   "+ v);
				label3.setText(label2.getText());
				
				case 8:
				if(v==8)label3.setText("残り   "+ v);
				label2.setText(label1.getText());
				
				case 9:
				if(v==9)label2.setText("残り   "+ v);
				label1.setText(str);
				textfield1.setText("");
				
				default:
				break;
					}
			if(TEXT.length()>20)limitedString = TEXT.substring(0,20);
			else limitedString = TEXT;
		
			}
			else if(i==0&&NUMBER%2==0) {
																			 //入力を一つずつずらす(後手用)
				switch(v) {
				
				case 0:
				label20.setText(label19.getText());
					
				case 1: 
				if(v==1)label20.setText("残り   "+ v);
				label19.setText(label18.getText());
				
				case 2:
				if(v==2)label19.setText("残り   "+ v);
				label18.setText(label17.getText());
				
				case 3:
				if(v==3)label18.setText("残り   "+ v);
				label17.setText(label16.getText());
				
				case 4:
				if(v==4)label17.setText("残り   "+ v);
				label16.setText(label15.getText());
				
				case 5:
				if(v==5)label16.setText("残り   "+ v);
				label15.setText(label14.getText());
				
				case 6:
				if(v==6)label15.setText("残り   "+ v);
				label14.setText(label13.getText());
				
				case 7:
				if(v==7)label14.setText("残り   "+ v);
				label13.setText(label12.getText());
				
				case 8:
				if(v==8)label13.setText("残り   "+ v);
				label12.setText(label11.getText());
				
				case 9:
				if(v==9)label12.setText("残り   "+ v);
				label11.setText(str);
				textfield1.setText("");
				
				default:
				break;
					}
				
			}
			
			else if(i>0){
				textfield1.setText(showResult(i));					//しりとり不成立はメッセージ表示
				button1.setVisible(false);							//ボタン表示(Send Answer -> Retry )切換
				button2.setVisible(true);
			}
			
//			String sql = "INSERT INTO WORDS (NUMBER, WORD, PLAYER) VALUES (?, ?, ?)";
			try {
			pps = con.prepareStatement(sql);
			pps.setInt(1, NUMBER);
			pps.setString(2,limitedString);
			pps.setString(3, "Java");
			pps.execute();
			}
			catch(SQLException sqex) {
				int sqer = sqex.getErrorCode();
			textfield1.setText("SQLｴﾗｰ: "+sqer);	
			}
			
			NUMBER++;
			if(NUMBER==21) {
				textfield1.setText("引き分けです");					//20回成功時
				button1.setVisible(false);
				button2.setVisible(true);
			}
		});

		button2.addActionListener(e -> {
																	//retryボタンclick時ｺｰﾄﾞ;
		SleepFor(200);
		NUMBER = 1;
		int y =0;
		y = (22-NUMBER)/2;
		
		label1.setText("残り   "+ y);										//表示リセット
		label2.setText("？ ？ ？");
		label3.setText("？ ？ ？");
		label4.setText("？ ？ ？");
		label5.setText("？ ？ ？");
		label6.setText("？ ？ ？");
		label7.setText("？ ？ ？");
		label8.setText("？ ？ ？");
		label9.setText("？ ？ ？");
		label10.setText("？ ？ ？");
		label11.setText("残り   "+ y);
		label12.setText("？ ？ ？");
		label13.setText("？ ？ ？");
		label14.setText("？ ？ ？");
		label15.setText("？ ？ ？");
		label16.setText("？ ？ ？");
		label17.setText("？ ？ ？");
		label18.setText("？ ？ ？");
		label19.setText("？ ？ ？");
		label20.setText("？ ？ ？");
	
		ansWords.clear();											///回答格納用配列リセット
		button1.setVisible(true);
		button2.setVisible(false);
		
		textfield1.setText("");
		
		TEXT="";
				
		});


		button3.addActionListener(e ->{SleepFor(300);
//		String sql = "DELETE FROM WORDS";
//		try {
//		pps = con.prepareStatement(sql);
//		pps.execute();
//		}
//		catch(SQLException sqex) {
//			int sqer = sqex.getErrorCode();
//		textfield1.setText("SQLｴﾗｰ: "+sqer);
//		}
		
		
		System.exit(0);});			//Exitイベント

	}
	public static void SleepFor(int i) {
		try {
			Thread.sleep(i);								//動作遅延用ｽﾘｰﾌﾟ

		}
		catch(InterruptedException e) {
			System.out.println(e.toString());

		}
	}
	public static int checkWords(String InputText, ArrayList<String> ansWords, ArrayList<String> dictionary) {
		int n=0;
		String string="";
		InputText = InputText.toUpperCase();
		if(InputText.length()==0)return 4;
		if(NUMBER==1&&!(InputText.startsWith("A"))) return 5;
		if(InputText.length()<3)return 2;
		if(ansWords.contains(InputText))
		{return 7;}						//すでに入力された文字列と一致した場合false

		else if((NUMBER>1)&&(!(TEXT.endsWith(InputText.substring(0,1)))))	
		{return 9;}						//しりとり不成立の場合はfalse 
		
		for(Iterator ite = dictionary.iterator(); (!(string = (String)ite.next()).equalsIgnoreCase(InputText))&&ite.hasNext();)
		{n++;}
		if(n>106332)return 6;												//n > 106332 は辞書内にマッチワードなし
		if(string.equalsIgnoreCase("END OF DICTIONARY"))return 6;
		else {ansWords.add(InputText); TEXT=InputText;return 0;}

/*		
		try {
		pps = con.prepareStatement("select word from words");
		pps.setString(1,InputText);
		rs = pps.executeQuery();
		rs.beforeFirst();
		n = rs.getRow();
		if(n==0) return 6;
		else return 0;
		}
					
		catch(SQLException sqe) {
		sqe.printStackTrace();
		return 8;
		}
*/		
		
	}
	
	public static String showResult(int i) {
		String result="";
		switch(i) {
		case 1: result = "  あなたの負けです ";break;
		case 2: result = "  単語が短すぎます ";break;
		case 3: result = "    ｱﾙﾌｧﾍﾞｯﾄ　のみ   ";break;
		case 4: result = "何も入力されていません";break;
		case 5: result = "　最初はA(a)からです ";break;
		case 6: result = " 辞書にありません ";break;
		case 7: result = " すでに使われた単語です ";break;
		case 8: result = " SQL ｴﾗｰ ";break;
		case 9: result = " しりとり不成立 ";break;
		case 10: result = "  ";break;
		default: break;
		}
		return result;
	}
	
}



