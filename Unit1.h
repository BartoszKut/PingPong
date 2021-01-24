//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *Timer_ball;
        TImage *left_paddle;
        TTimer *left_up;
        TTimer *left_down;
        TTimer *right_up;
        TTimer *right_down;
        TImage *right_paddle;
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall left_upTimer(TObject *Sender);
        void __fastcall left_downTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall right_upTimer(TObject *Sender);
        void __fastcall right_downTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
