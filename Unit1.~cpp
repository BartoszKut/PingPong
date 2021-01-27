//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;
int player_1_points = 0;
int player_2_points = 0;
int bounces = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
        //ball movment
        ball->Left += x;
        ball->Top += y;

        //ball bounce top
        if (ball->Top <= background->Top) y = -y;

        //ball bounce down
        if (ball->Top + ball->Height + 5 >= background->Top + background->Height) y = -y;

        //win point by player 2
        if(ball->Left + ball->Width <= left_paddle->Left + left_paddle->Width - 10) {
            player_2_points++;

            scores_p2->Caption = player_2_points;
            Timer_ball->Enabled = false;
            ball->Visible = false;

            if(player_2_points < 3){
                information->Caption = "Punkt zdobywa gracz nr 2! Start za: 2 sek.";
                information->Visible = true;
                how_much_bounces->Caption = "Iloœæ odbiæ: " + IntToStr(bounces) ;
                how_much_bounces->Visible = true;
                Application->ProcessMessages(); Sleep(1000);
                information->Caption = "Punkt zdobywa gracz nr 2! Start za: 1 sek.";
                Application->ProcessMessages(); Sleep(1000);
                information->Visible = false;
                how_much_bounces->Visible = false;

                ball->Left = background->Width - 50;
                ball->Top = 50;
                ball->Visible = true;
                x = -8; y = -8;
                Timer_ball->Enabled = true;
                bounces = 0;
            }
        }

        //win point by player 1
        else if (ball->Left + ball->Width >= right_paddle->Left + 10) {
            player_1_points++;

            scores_p1->Caption = player_1_points;
            Timer_ball->Enabled = false;
            ball->Visible = false;

            if(player_1_points < 3){
                information->Caption = "Punkt zdobywa gracz nr 1! Start za: 2 sek.";
                information->Visible = true;
                how_much_bounces->Caption = "Iloœæ odbiæ: " + IntToStr(bounces);
                how_much_bounces->Visible = true;
                Application->ProcessMessages(); Sleep(1000);
                information->Caption = "Punkt zdobywa gracz nr 1! Start za: 1 sek.";
                Application->ProcessMessages(); Sleep(1000);
                information->Visible = false;
                how_much_bounces->Visible = false;

                ball->Left = 50;
                ball->Top = 50;
                ball->Visible = true;
                x = 8; y = -8;
                Timer_ball->Enabled = true;
                bounces = 0;
            }
        }
        //ball reflection from left paddle
        else if ((ball -> Top > left_paddle -> Top - ball -> Height) &&
                (ball -> Top < left_paddle -> Top + left_paddle -> Height + ball -> Height) &&
                (ball -> Left <= left_paddle -> Left + left_paddle -> Width))
        {
                if (ball->Top + ball->Height <= left_paddle->Top + left_paddle->Height/3) {
                    if(x<0) {
                        if (x < -8) x = x+2;
                        else x = -8;
                        x = -x;
                        bounces++;
                    }
                }
                else if (ball->Top > left_paddle->Top + left_paddle->Height/3 &&
                        ball->Top + ball->Height < left_paddle->Top + left_paddle->Height - left_paddle->Height/3) {
                    if(x<0) {
                        x = x-2;
                        x = -x;
                        bounces++;
                    }
                }

                else if (ball->Top >= left_paddle->Top + left_paddle->Height - left_paddle->Height/3) {

                    if(x<0) {
                        if (x < -8) x = x+2;
                        else x = -8;
                        x = -x;
                        bounces++;
                    }
                }

                else {
                if(x<0) {
                        x = -x;
                        bounces++;
                    }
                }
        }

        //ball reflection from right paddle
        else if ((ball -> Top > right_paddle -> Top - ball -> Height) &&
                (ball -> Top < right_paddle -> Top + right_paddle -> Height + ball -> Height) &&
                (ball -> Left + ball -> Width >= right_paddle -> Left))
        {
                if (ball->Top + ball->Height <= right_paddle->Top + right_paddle->Height/3) {

                    if(x>0){
                        if (x>8) x = x-2;
                        else x = 8;
                        x = -x;
                        bounces++;
                    }
                }
                else if (ball->Top > right_paddle->Top + right_paddle->Height/3 &&
                        ball->Top + ball->Height < right_paddle->Top + right_paddle->Height - right_paddle->Height/3) {
                    if(x>0) {
                        x = x+2;
                        x = -x;
                        bounces++;
                    }
                }

                else if (ball->Top >= right_paddle->Top + right_paddle->Height - right_paddle->Height/3) {
                    if(x>0) {
                        if (x>8) x = x-2;
                        else x = 8;
                        x = -x;
                        bounces++;
                    }
                }
                else {
                if(x>0) {
                        x = -x;
                        bounces++;
                    }
                }
        }

        //players wins game
        if (player_1_points >=3) {
                p1_win->Visible = true;
                Timer_ball->Enabled = false;
                ball->Visible = false;
                how_much_bounces->Caption = "Iloœæ odbiæ: " + IntToStr(bounces);
                how_much_bounces->Visible = true;
        }

        if (player_2_points >=3) {
                p2_win->Visible = true;
                Timer_ball->Enabled = false;
                ball->Visible = false;
                how_much_bounces->Caption = "Iloœæ odbiæ: " + IntToStr(bounces);
                how_much_bounces->Visible = true;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::left_upTimer(TObject *Sender)
{
        if(left_paddle->Top > 10)
            left_paddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::left_downTimer(TObject *Sender)
{
        if(left_paddle->Top + left_paddle->Height < background->Height - 10)
            left_paddle->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::right_upTimer(TObject *Sender)
{
        if(right_paddle->Top > 10)
            right_paddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::right_downTimer(TObject *Sender)
{
        if(right_paddle->Top + right_paddle->Height < background->Height - 10)
        right_paddle->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        //paddles movement (up&down)
        if (Key == 0x41) left_up->Enabled = true;
        if (Key == 0x5A) left_down->Enabled = true;
        if (Key == VK_UP) right_up->Enabled = true;
        if (Key == VK_DOWN) right_down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        //paddles stop movement
        if (Key == 0x41) left_up->Enabled = false;
        if (Key == 0x5A) left_down->Enabled = false;
        if (Key == VK_UP) right_up->Enabled = false;
        if (Key == VK_DOWN) right_down->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p1_winClick(TObject *Sender)
{
        ball->Left = 50;
        ball->Top = 50;

        ball->Visible = true;
        x = 8; y = -8;
        Timer_ball->Enabled = true;

        p1_win->Visible = false;

        player_1_points = 0;
        player_2_points = 0;
        scores_p1->Caption = player_1_points;
        scores_p2->Caption = player_2_points;

        how_much_bounces->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p2_winClick(TObject *Sender)
{
        ball->Left = background->Width - 50;
        ball->Top = 50;

        ball->Visible = true;
        x = -8; y = -8;
        Timer_ball->Enabled = true;

        p2_win->Visible = false;

        player_1_points = 0;
        player_2_points = 0;
        scores_p1->Caption = player_1_points;
        scores_p2->Caption = player_2_points;

        how_much_bounces->Visible = false;
}
//---------------------------------------------------------------------------


