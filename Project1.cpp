//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                Application->Initialize();
                Application->CreateForm(__classid(TForm1), &Form1);
                AnsiString first = "Witaj w grze PingPong";
                AnsiString second = "Lewy gracz steruje wciskaj¹c klawisze A oraz Z";
                AnsiString third = "Prawy gracz steruje wciskaj¹c strza³ki w górê i w dó³";
                AnsiString fourth = "Odbijaj¹c pi³eczkê œrodkiem paletki przyœpieszy ona oraz zmniejszy siê k¹t odbicia.";
                AnsiString fifth = "Mo¿esz dowolnie ustawiaæ pole gry";
                AnsiString sixth = "Udanej zabawy!";
                ShowMessage(first + sLineBreak + sLineBreak + second + sLineBreak + third + sLineBreak + sLineBreak + fourth + sLineBreak + fifth + sLineBreak + sLineBreak + sixth);
                Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
