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

		static int NUMBER = 1;                                      //�񓚉񐔃J�E���^�[
		static int temp   = 0;

		static string convertedUnicodeString = "";                 //UnicodeString����string�^�ɕϊ����Ċi�[
																   //C++�e��֐����p�̂���

		static UnicodeString LINE  = "";                            //Edit1���͊i�[�pUnicodeString�O���[�o���ϐ�
		static UnicodeString TEXT_PREV = " ";                       //�P�O�̓��͊i�[�pUnicodeString�O���[�o���ϐ�

		static UnicodeString dbString = "";                         //�ް��ް�����擾�p������
		static vector<string> dictionary(106332);                  //�����t�@�C���f�[�^�i�[�p�ϒ��z��
		static vector<string> ansWords(20);     					//���͒P��i�[�p�ϒ��z��
		static String DataBase = "localhost:C:/Users/Public/Documents/Embarcadero/Studio/20.0/Samples/Data/DB1.IB";

		//---------------------------------------------------------------------------
		#pragma package(smart_init)
		#pragma resource "*.dfm"
		TForm1 *Form1;

		//---------------------------------------------------------------------------

		int checkWord(UnicodeString str) {                          //���̓`�F�b�N�֐�
		int n = 0;
		int length = convertedUnicodeString.length();
		string temp (((AnsiString)str).c_str());
		string startstr = temp.substr(0,1);
		string temp_prev (((AnsiString)TEXT_PREV).c_str());
		string end_prev = temp_prev.substr(temp_prev.length()-1);

		if(NUMBER==1&&startstr!="A") return 5;                        //�n�܂肪A�łȂ��ꍇ�̏���

		if(length==0){return 4;}                                      //�����͎��̏���

		if(!regex_match(convertedUnicodeString, regex("^[A-Z]+$"))){  //���͂�(A�`Z)���𔻒肷�鏈��
		return 3;}

		if(NUMBER>1&&end_prev!=startstr)return 9;                      //����Ƃ�s�������̏���

		if(length<3) return 2;

		//�����������ĒP�ꂪ�Ȃ��ꍇ�̏���
		if(find(dictionary.begin(), dictionary.end(), convertedUnicodeString)==dictionary.end())return 6;

		//���ɓ��͂��ꂽ�P��ƈ�v���邩����
		if(find(ansWords.begin(), ansWords.end(), convertedUnicodeString)!=ansWords.end())return 7;

		return 0;

		}

		//---------------------------------------------------------------------------

		UnicodeString showResult(int i){
			   UnicodeString result="";                                  //�Q�[���I�����̌��ʕ\��
			   switch(i){
				case 1: result = "  ���Ȃ��̕����ł� ";break;
				case 2: result = "  �P�ꂪ�Z�����܂� ";break;
				case 3: result = "    ��̧�ޯā@�̂�   ";break;
				case 4: result = "�������͂���Ă��܂���";break;
				case 5: result = "�@�ŏ���A(a)����ł� ";break;
				case 6: result = " �����ɂ���܂��� ";break;
				case 7: result = " ���łɎg��ꂽ�P��ł� ";break;
				case 8: result = " ���Ѵװ ";break;
				case 9: result = " ����Ƃ�s���� ";break;
				case 10: result = " ý� ";break;
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
		{                                                               //Send Answer �̏���


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
																		 //�\�������炷(���p)
		case 0:
		Label10->Caption = Label9->Caption;
		case 1:
		if(x==1)Label10->Caption = "�c��    "+IntToStr(x);
		Label9->Caption = Label8->Caption;
		case 2:
		if(x==2)Label9->Caption = "�c��    "+IntToStr(x);
		Label8->Caption = Label7->Caption;
		case 3:
		if(x==3)Label8->Caption = "�c��    "+IntToStr(x);
		Label7->Caption = Label6->Caption;
		case 4:
		if(x==4)Label7->Caption = "�c��    "+IntToStr(x);
		Label6->Caption = Label5->Caption;
		case 5:
		if(x==5)Label6->Caption = "�c��    "+IntToStr(x);
		Label5->Caption = Label4->Caption;
		case 6:
		if(x==6)Label5->Caption = "�c��    "+IntToStr(x);
		Label4->Caption = Label3->Caption;
		case 7:
		if(x==7)Label4->Caption = "�c��    "+IntToStr(x);
		Label3->Caption = Label2->Caption;
		case 8:
		if(x==8)Label3->Caption = "�c��    "+IntToStr(x);
		Label2->Caption = Label1->Caption;
		case 9:
		if(x==9)Label2->Caption = "�c��    "+IntToStr(x);
		Label1->Caption = str;
		Edit1->Text = ""; break;

		default:
		break;
				}

			}
		}


		if(NUMBER%2==0){

																			 //�\�������炷(���p)
		switch(x){

		case 0:
		Label20->Caption = Label19->Caption;
		case 1:
		if(x==1)Label20->Caption = "�c��    "+IntToStr(x);
		Label19->Caption = Label18->Caption;
		case 2:
		if(x==2)Label19->Caption = "�c��    "+IntToStr(x);
		Label18->Caption = Label17->Caption;
		case 3:
		if(x==3)Label18->Caption = "�c��    "+IntToStr(x);
		Label17->Caption = Label16->Caption;
		case 4:
		if(x==4)Label17->Caption = "�c��    "+IntToStr(x);
		Label16->Caption = Label15->Caption;
		case 5:
		if(x==5)Label16->Caption = "�c��    "+IntToStr(x);
		Label15->Caption = Label14->Caption;
		case 6:
		if(x==6)Label15->Caption = "�c��    "+IntToStr(x);
		Label14->Caption = Label13->Caption;
		case 7:
		if(x==7)Label14->Caption = "�c��    "+IntToStr(x);
		Label13->Caption = Label12->Caption;
		case 8:
		if(x==8)Label13->Caption = "�c��    "+IntToStr(x);
		Label12->Caption = Label11->Caption;
		case 9:
		if(x==9)Label12->Caption = "�c��    "+IntToStr(x);
		Label11->Caption = str;
		Edit1->Text = ""; break;

		default:
		break;
			}


		}

		//�������ꍇ�̕\���ƃ��Z�b�g����											�@�@�@
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
		Edit1->Text = "�װ";}

		NUMBER++;
																 //20�񐳏�I����
		if(NUMBER==21){
		Edit1->Text = "���������ł�";
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
		int x=0;                                                          //retry�{�^���̱���ݲ����

		Button3->Visible = false;
		Button1->Visible = true;
		Edit1->Text = "";
		NUMBER=1;
		LINE = "";
		TEXT_PREV = " ";
		ansWords.clear();

		x=(21-NUMBER)/2;

		Label1->Caption  =  "�c��   "+IntToStr(x);
		Label2->Caption  =  "�H �H �H";
		Label3->Caption  =  "�H �H �H";
		Label4->Caption  =  "�H �H �H";
		Label5->Caption  =  "�H �H �H";
		Label6->Caption  =  "�H �H �H";
		Label7->Caption  =  "�H �H �H";
		Label8->Caption  =  "�H �H �H";
		Label9->Caption  =  "�H �H �H";
		Label10->Caption =  "�H �H �H";
		Label11->Caption =  "�c��   "+IntToStr(x);
		Label12->Caption =  "�H �H �H";
		Label13->Caption =  "�H �H �H";
		Label14->Caption =  "�H �H �H";
		Label15->Caption =  "�H �H �H";
		Label16->Caption =  "�H �H �H";
		Label17->Caption =  "�H �H �H";
		Label18->Caption =  "�H �H �H";
		Label19->Caption =  "�H �H �H";
		Label20->Caption =  "�H �H �H";

		}
		//---------------------------------------------------------------------------




		void __fastcall TForm1::FormCreate(TObject *Sender)
		{

		FDConnection1->Params->Database =  DataBase;
		int x=0;                                                 //������ʐݒ�Ǝ����t�@�C���̓ǂݍ���
		x=(21-NUMBER)/2;

		Label1->Caption  =  "�c��   "+IntToStr(x);
		Label2->Caption  =  "�H �H �H";
		Label3->Caption  =  "�H �H �H";
		Label4->Caption  =  "�H �H �H";
		Label5->Caption  =  "�H �H �H";
		Label6->Caption  =  "�H �H �H";
		Label7->Caption  =  "�H �H �H";
		Label8->Caption  =  "�H �H �H";
		Label9->Caption  =  "�H �H �H";
		Label10->Caption =  "�H �H �H";
		Label11->Caption =  "�c��   "+IntToStr(x);
		Label12->Caption =  "�H �H �H";
		Label13->Caption =  "�H �H �H";
		Label14->Caption =  "�H �H �H";
		Label15->Caption =  "�H �H �H";
		Label16->Caption =  "�H �H �H";
		Label17->Caption =  "�H �H �H";
		Label18->Caption =  "�H �H �H";
		Label19->Caption =  "�H �H �H";
		Label20->Caption =  "�H �H �H";

		string filetext = "";
		ifstream ifs("C:/Shiritori Files/EnglishDictionary.txt");

		if(! ifs){
		Edit1->Text=" ���Ѵװ ";
		Button1->Visible=false;
		Button3->Visible=true;
		}

		while(getline(ifs,filetext)){
		dictionary.push_back(filetext);

		if(! ifs){
		Edit1->Text=" ���Ѵװ ";
		Button1->Visible=false;
		Button3->Visible=true;
				}
			}

		}
		//---------------------------------------------------------------------------

