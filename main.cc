#include "Note.hh"
#include "Accords.hh"

void testNote()
{
  Note tonique(Do);
  cout << tonique << endl;

  Note quinte(tonique);
  quinte += 7;
  cout << quinte << "  ";
  if(tonique != quinte){
    cout << "comparaison ok !" << endl;
  }

  tonique += 16;
  cout << tonique << endl;
}
void testAccord()
{
  Note tonique(Dod);
  Accord DoMaj(tonique);
  Accord CMaj(DoMaj);
  cout << DoMaj << "  " << CMaj << endl;
  cout << (DoMaj != CMaj) << endl;
}
void testPowerChord()
{
  Note LA(La);
  PowerChord A5(LA, true);
  cout << A5 << endl;
  PowerChord La5(A5);
  cout << La5 << " " << A5 << endl;
  cout << (La5 == A5) << endl;
}
void testTroisSons(){
  Note DO(Do);
  TroisSons Cm(DO, true, false);
  TroisSons C(DO, false, false);
  cout << Cm << endl;
  cout << (C != Cm) << endl;
}
void testQuatreSons(){
  Note DO(Do);
  QuatreSons CM7(DO, false, false, false);
  QuatreSons C7(DO, false, true, false);
  cout << CM7 << endl;
  cout << (CM7 == C7) << " " << (CM7 != C7) << endl;
}

int main(){
  // testNote();
  // testAccord();
  // testPowerChord();
  // testTroisSons();
  testQuatreSons();
  return 0;
}
