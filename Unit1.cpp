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

        //lost point
        if(ball->Left < left_paddle->Left + left_paddle->Width ||
        ball->Left + ball->Width > right_paddle->Left)
        {
            Timer_ball->Enabled = false;
            ball->Visible = false;
        }
        //ball reflection
        else if ((ball->Left > left_paddle->Left + left_paddle->Width &&
                ball->Top > left_paddle->Top - ball->Height/2 &&
                ball->Top + ball->Height < left_paddle->Top + left_paddle->Height + ball->Height/2) ||
                (ball->Left + ball->Width < right_paddle->Left &&
                 ball->Top > right_paddle->Top - ball->Height/2 &&
                 ball->Top + ball->Height < right_paddle->Top + right_paddle->Height + ball->Height/2))
        {
             if(x>0) x = -x;
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







