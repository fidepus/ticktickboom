/*
 Bomb

 Selects a random category and card, turns on a timer with a LED connected to digital
 pin 13 and a ticking buzzer connected to digital
 pin 3, when pressing a pushbutton attached to pin 2.
 Then it gives out a text on the lcd.
 After the time is up the buzzer will make a noise for
 a second.


 The circuit:
 * LED attached from pin 13 to ground
 * buzzer attached from pin 3 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 created 2010
 by fidepus <http://www.fidepus.de>
 with the help of several tutorials at

 http://www.arduino.cc/
 */

// include the library code:
#include <LiquidCrystal.h>
#include <avr/pgmspace.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buzzerPin = 3;     // the number of the Buzzer pin
const int ledPin =  13;      // the number of the LED pin

// strings with texts for display, will be picked randomly

prog_char original_string_0[] PROGMEM = "AUL"; 
prog_char original_string_1[] PROGMEM = "GLA";
prog_char original_string_2[] PROGMEM = "SE";
prog_char original_string_3[] PROGMEM = "HE";
prog_char original_string_4[] PROGMEM = "HIE";
prog_char original_string_5[] PROGMEM = "SI";
prog_char original_string_6[] PROGMEM = "DRI";
prog_char original_string_7[] PROGMEM = "ZIE";
prog_char original_string_8[] PROGMEM = "AU";
prog_char original_string_9[] PROGMEM = "FU"; 
prog_char original_string_10[] PROGMEM = "STE"; 
prog_char original_string_11[] PROGMEM = "KRA"; 
prog_char original_string_12[] PROGMEM = "EI"; 
prog_char original_string_13[] PROGMEM = "KRI"; 
prog_char original_string_14[] PROGMEM = "PA"; 
prog_char original_string_15[] PROGMEM = "DEU"; 
prog_char original_string_16[] PROGMEM = "ITZ"; 
prog_char original_string_17[] PROGMEM = "OR"; 
prog_char original_string_18[] PROGMEM = "OCH";
prog_char original_string_19[] PROGMEM = "UND"; 
prog_char original_string_20[] PROGMEM = "ACH"; 
prog_char original_string_21[] PROGMEM = "KO"; 
prog_char original_string_22[] PROGMEM = "URM"; 
prog_char original_string_23[] PROGMEM = "MEL"; 
prog_char original_string_24[] PROGMEM = "ACK"; 
prog_char original_string_25[] PROGMEM = "END"; 
prog_char original_string_26[] PROGMEM = "AL"; 
prog_char original_string_27[] PROGMEM = "ZWE"; 
prog_char original_string_28[] PROGMEM = "GE";
prog_char original_string_29[] PROGMEM = "NIE"; 
prog_char original_string_30[] PROGMEM = "ERZ"; 
prog_char original_string_31[] PROGMEM = "ISCH"; 
prog_char original_string_32[] PROGMEM = "EHR"; 
prog_char original_string_33[] PROGMEM = "IND"; 
prog_char original_string_34[] PROGMEM = "NE"; 
prog_char original_string_35[] PROGMEM = "ERB"; 
prog_char original_string_36[] PROGMEM = "MA "; 
prog_char original_string_37[] PROGMEM = "UM"; 
prog_char original_string_38[] PROGMEM = "MER";
prog_char original_string_39[] PROGMEM = "WET"; 
prog_char original_string_40[] PROGMEM = "GRU"; 
prog_char original_string_41[] PROGMEM = "STEL"; 
prog_char original_string_42[] PROGMEM = "WAL"; 
prog_char original_string_43[] PROGMEM = "WEN"; 
prog_char original_string_44[] PROGMEM = "EU"; 
prog_char original_string_45[] PROGMEM = "BES"; 
prog_char original_string_46[] PROGMEM = "ACHS"; 
prog_char original_string_47[] PROGMEM = "EIG"; 
prog_char original_string_48[] PROGMEM = "UN";
prog_char original_string_49[] PROGMEM = "REI"; 
prog_char original_string_50[] PROGMEM = "SIT"; 
prog_char original_string_51[] PROGMEM = "BI"; 
prog_char original_string_52[] PROGMEM = "RE"; 
prog_char original_string_53[] PROGMEM = "PEL"; 
prog_char original_string_54[] PROGMEM = "TIG";

PROGMEM const char *original_string_table[] = 	   // change "original_string_table" name to suit
{   
  original_string_0,
  original_string_1,
  original_string_2,
  original_string_3,
  original_string_4,
  original_string_5,
  original_string_6,
  original_string_7,
  original_string_8,
  original_string_9,
  original_string_10,
  original_string_11,
  original_string_12,
  original_string_13,
  original_string_14,
  original_string_15,
  original_string_16,
  original_string_17,
  original_string_18,
  original_string_19,
  original_string_20,
  original_string_21,
  original_string_22,
  original_string_23,
  original_string_24,
  original_string_25,
  original_string_26,
  original_string_27,
  original_string_28,
  original_string_29,
  original_string_30,
  original_string_31,
  original_string_32,
  original_string_33,
  original_string_34,
  original_string_35,
  original_string_36,
  original_string_37,
  original_string_38,
  original_string_39,
  original_string_40,
  original_string_41,
  original_string_42,
  original_string_43,
  original_string_44,
  original_string_45,
  original_string_46,
  original_string_47,
  original_string_48,
  original_string_49,
  original_string_50,
  original_string_51,
  original_string_52,
  original_string_53,
  original_string_54
  };

char original[255];    // make sure this is large enough for the largest string it must hold
// boolean array to indicate if a card has already been played
boolean originalUsed[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int originalCounter = 0;    // count the used cards of this cat.

prog_char bekannt_string_0[] PROGMEM = "EE"; 
prog_char bekannt_string_1[] PROGMEM = "RL";
prog_char bekannt_string_2[] PROGMEM = "KS";
prog_char bekannt_string_3[] PROGMEM = "AE";
prog_char bekannt_string_4[] PROGMEM = "AG";
prog_char bekannt_string_5[] PROGMEM = "AH";
prog_char bekannt_string_6[] PROGMEM = "AJ";
prog_char bekannt_string_7[] PROGMEM = "AK";
prog_char bekannt_string_8[] PROGMEM = "AN";
prog_char bekannt_string_9[] PROGMEM = "AS"; 
prog_char bekannt_string_10[] PROGMEM = "NC"; 
prog_char bekannt_string_11[] PROGMEM = "OW"; 
prog_char bekannt_string_12[] PROGMEM = "TB"; 
prog_char bekannt_string_13[] PROGMEM = "FD"; 
prog_char bekannt_string_14[] PROGMEM = "HK"; 
prog_char bekannt_string_15[] PROGMEM = "HP"; 
prog_char bekannt_string_16[] PROGMEM = "HQ"; 
prog_char bekannt_string_17[] PROGMEM = "JD"; 
prog_char bekannt_string_18[] PROGMEM = "JH";
prog_char bekannt_string_19[] PROGMEM = "DD"; 
prog_char bekannt_string_20[] PROGMEM = "BS"; 
prog_char bekannt_string_21[] PROGMEM = "LA"; 
prog_char bekannt_string_22[] PROGMEM = "PB"; 
prog_char bekannt_string_23[] PROGMEM = "AA"; 
prog_char bekannt_string_24[] PROGMEM = "ML"; 
prog_char bekannt_string_25[] PROGMEM = "CD"; 
prog_char bekannt_string_26[] PROGMEM = "AC"; 
prog_char bekannt_string_27[] PROGMEM = "FP"; 
prog_char bekannt_string_28[] PROGMEM = "TM";
prog_char bekannt_string_29[] PROGMEM = "NS"; 
prog_char bekannt_string_30[] PROGMEM = "AD"; 
prog_char bekannt_string_31[] PROGMEM = "GK"; 
prog_char bekannt_string_32[] PROGMEM = "GP"; 
prog_char bekannt_string_33[] PROGMEM = "GV"; 
prog_char bekannt_string_34[] PROGMEM = "HG"; 
prog_char bekannt_string_35[] PROGMEM = "NI"; 
prog_char bekannt_string_36[] PROGMEM = "MM"; 
prog_char bekannt_string_37[] PROGMEM = "KK"; 
prog_char bekannt_string_38[] PROGMEM = "BK";
prog_char bekannt_string_39[] PROGMEM = "RW"; 
prog_char bekannt_string_40[] PROGMEM = "GG"; 
prog_char bekannt_string_41[] PROGMEM = "ES"; 
prog_char bekannt_string_42[] PROGMEM = "EP"; 
prog_char bekannt_string_43[] PROGMEM = "DL"; 
prog_char bekannt_string_44[] PROGMEM = "WM"; 
prog_char bekannt_string_45[] PROGMEM = "WB"; 
prog_char bekannt_string_46[] PROGMEM = "VK"; 
prog_char bekannt_string_47[] PROGMEM = "LA"; 
prog_char bekannt_string_48[] PROGMEM = "LB";
prog_char bekannt_string_49[] PROGMEM = "RS"; 
prog_char bekannt_string_50[] PROGMEM = "MR"; 
prog_char bekannt_string_51[] PROGMEM = "BP"; 
prog_char bekannt_string_52[] PROGMEM = "WS"; 
prog_char bekannt_string_53[] PROGMEM = "BD"; 
prog_char bekannt_string_54[] PROGMEM = "JS";

PROGMEM const char *bekannt_string_table[] = 	   // change "bekannt_string_table" name to suit
{   
  bekannt_string_0,
  bekannt_string_1,
  bekannt_string_2,
  bekannt_string_3,
  bekannt_string_4,
  bekannt_string_5,
  bekannt_string_6,
  bekannt_string_7,
  bekannt_string_8,
  bekannt_string_9,
  bekannt_string_10,
  bekannt_string_11,
  bekannt_string_12,
  bekannt_string_13,
  bekannt_string_14,
  bekannt_string_15,
  bekannt_string_16,
  bekannt_string_17,
  bekannt_string_18,
  bekannt_string_19,
  bekannt_string_20,
  bekannt_string_21,
  bekannt_string_22,
  bekannt_string_23,
  bekannt_string_24,
  bekannt_string_25,
  bekannt_string_26,
  bekannt_string_27,
  bekannt_string_28,
  bekannt_string_29,
  bekannt_string_30,
  bekannt_string_31,
  bekannt_string_32,
  bekannt_string_33,
  bekannt_string_34,
  bekannt_string_35,
  bekannt_string_36,
  bekannt_string_37,
  bekannt_string_38,
  bekannt_string_39,
  bekannt_string_40,
  bekannt_string_41,
  bekannt_string_42,
  bekannt_string_43,
  bekannt_string_44,
  bekannt_string_45,
  bekannt_string_46,
  bekannt_string_47,
  bekannt_string_48,
  bekannt_string_49,
  bekannt_string_50,
  bekannt_string_51,
  bekannt_string_52,
  bekannt_string_53,
  bekannt_string_54
  };

char bekannt[255];    // make sure this is large enough for the largest string it must hold

int bekanntCounter = 0;    // count the used cards of this category
// boolean array to indicate if a card has already been played
boolean bekanntUsed[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

prog_char angesetzt_string_0[] PROGMEM = "TON"; 
prog_char angesetzt_string_1[] PROGMEM = "VOR";
prog_char angesetzt_string_2[] PROGMEM = "HAUPT";
prog_char angesetzt_string_3[] PROGMEM = "KNALL";
prog_char angesetzt_string_4[] PROGMEM = "STADT";
prog_char angesetzt_string_5[] PROGMEM = "LICHT";
prog_char angesetzt_string_6[] PROGMEM = "PRALL";
prog_char angesetzt_string_7[] PROGMEM = "LEBEN";
prog_char angesetzt_string_8[] PROGMEM = "WEICH";
prog_char angesetzt_string_9[] PROGMEM = "SCHNEE"; 
prog_char angesetzt_string_10[] PROGMEM = "LADEN"; 
prog_char angesetzt_string_11[] PROGMEM = "RECHT"; 
prog_char angesetzt_string_12[] PROGMEM = "NACHT"; 
prog_char angesetzt_string_13[] PROGMEM = "SCHEIN"; 
prog_char angesetzt_string_14[] PROGMEM = "UNTER"; 
prog_char angesetzt_string_15[] PROGMEM = "REISE"; 
prog_char angesetzt_string_16[] PROGMEM = "KURZ"; 
prog_char angesetzt_string_17[] PROGMEM = "BLUT"; 
prog_char angesetzt_string_18[] PROGMEM = "STEIN";
prog_char angesetzt_string_19[] PROGMEM = "UEBER"; 
prog_char angesetzt_string_20[] PROGMEM = "LANG"; 
prog_char angesetzt_string_21[] PROGMEM = "PANZER"; 
prog_char angesetzt_string_22[] PROGMEM = "TEE"; 
prog_char angesetzt_string_23[] PROGMEM = "DOPPEL"; 
prog_char angesetzt_string_24[] PROGMEM = "HAUS"; 
prog_char angesetzt_string_25[] PROGMEM = "FISCH"; 
prog_char angesetzt_string_26[] PROGMEM = "KATZE"; 
prog_char angesetzt_string_27[] PROGMEM = "ERST"; 
prog_char angesetzt_string_28[] PROGMEM = "STRICH";
prog_char angesetzt_string_29[] PROGMEM = "FAMILIE"; 
prog_char angesetzt_string_30[] PROGMEM = "FREI"; 
prog_char angesetzt_string_31[] PROGMEM = "HAND"; 
prog_char angesetzt_string_32[] PROGMEM = "BETT"; 
prog_char angesetzt_string_33[] PROGMEM = "OFFEN"; 
prog_char angesetzt_string_34[] PROGMEM = "FUSS"; 
prog_char angesetzt_string_35[] PROGMEM = "TAG"; 
prog_char angesetzt_string_36[] PROGMEM = "KOPF"; 
prog_char angesetzt_string_37[] PROGMEM = "SAND"; 
prog_char angesetzt_string_38[] PROGMEM = "MAEDCHEN";
prog_char angesetzt_string_39[] PROGMEM = "FINGER"; 
prog_char angesetzt_string_40[] PROGMEM = "BUTTER"; 
prog_char angesetzt_string_41[] PROGMEM = "TEST"; 
prog_char angesetzt_string_42[] PROGMEM = "SONNE"; 
prog_char angesetzt_string_43[] PROGMEM = "EXPRESS"; 
prog_char angesetzt_string_44[] PROGMEM = "HEIM"; 
prog_char angesetzt_string_45[] PROGMEM = "LUECKE"; 
prog_char angesetzt_string_46[] PROGMEM = "SUCHT"; 
prog_char angesetzt_string_47[] PROGMEM = "FEUER"; 
prog_char angesetzt_string_48[] PROGMEM = "HOCH";
prog_char angesetzt_string_49[] PROGMEM = "TOLL"; 
prog_char angesetzt_string_50[] PROGMEM = "ERST"; 
prog_char angesetzt_string_51[] PROGMEM = "BALL"; 
prog_char angesetzt_string_52[] PROGMEM = "GROSS"; 
prog_char angesetzt_string_53[] PROGMEM = "QUER"; 
prog_char angesetzt_string_54[] PROGMEM = "HUND";

PROGMEM const char *angesetzt_string_table[] = 	   // change "angesetzt_string_table" name to suit
{   
  angesetzt_string_0,
  angesetzt_string_1,
  angesetzt_string_2,
  angesetzt_string_3,
  angesetzt_string_4,
  angesetzt_string_5,
  angesetzt_string_6,
  angesetzt_string_7,
  angesetzt_string_8,
  angesetzt_string_9,
  angesetzt_string_10,
  angesetzt_string_11,
  angesetzt_string_12,
  angesetzt_string_13,
  angesetzt_string_14,
  angesetzt_string_15,
  angesetzt_string_16,
  angesetzt_string_17,
  angesetzt_string_18,
  angesetzt_string_19,
  angesetzt_string_20,
  angesetzt_string_21,
  angesetzt_string_22,
  angesetzt_string_23,
  angesetzt_string_24,
  angesetzt_string_25,
  angesetzt_string_26,
  angesetzt_string_27,
  angesetzt_string_28,
  angesetzt_string_29,
  angesetzt_string_30,
  angesetzt_string_31,
  angesetzt_string_32,
  angesetzt_string_33,
  angesetzt_string_34,
  angesetzt_string_35,
  angesetzt_string_36,
  angesetzt_string_37,
  angesetzt_string_38,
  angesetzt_string_39,
  angesetzt_string_40,
  angesetzt_string_41,
  angesetzt_string_42,
  angesetzt_string_43,
  angesetzt_string_44,
  angesetzt_string_45,
  angesetzt_string_46,
  angesetzt_string_47,
  angesetzt_string_48,
  angesetzt_string_49,
  angesetzt_string_50,
  angesetzt_string_51,
  angesetzt_string_52,
  angesetzt_string_53,
  angesetzt_string_54
  };

char angesetzt[255];    // make sure this is large enough for the largest string it must hold

int angesetztCounter = 0; // count the used cards of this category
// boolean array to indicate if a card has already been played
boolean angesetztUsed[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

prog_char geschuettelt_string_0[] PROGMEM = "TTIWGEERTFNOR"; 
prog_char geschuettelt_string_1[] PROGMEM = "LERSCHMLIFAUSPEI";
prog_char geschuettelt_string_2[] PROGMEM = "SUBTELLESELTAH";
prog_char geschuettelt_string_3[] PROGMEM = "FIKUTRTESCH";
prog_char geschuettelt_string_4[] PROGMEM = "BOTRHAFVER";
prog_char geschuettelt_string_5[] PROGMEM = "NETONKNAHBTOAU";
prog_char geschuettelt_string_6[] PROGMEM = "ELGOVREDEF";
prog_char geschuettelt_string_7[] PROGMEM = "NEMHRALIBDER";
prog_char geschuettelt_string_8[] PROGMEM = "RHEWREEFU";
prog_char geschuettelt_string_9[] PROGMEM = "EISCHNIDLW"; 
prog_char geschuettelt_string_10[] PROGMEM = "SCHDERGALENI"; 
prog_char geschuettelt_string_11[] PROGMEM = "LIMKALEDNAW"; 
prog_char geschuettelt_string_12[] PROGMEM = "MMSOERBAULRU"; 
prog_char geschuettelt_string_13[] PROGMEM = "KUCHNGINOHEBEL"; 
prog_char geschuettelt_string_14[] PROGMEM = "TTSCHALURBELT"; 
prog_char geschuettelt_string_15[] PROGMEM = "DELNPPEUSU"; 
prog_char geschuettelt_string_16[] PROGMEM = "SCHNENABANALE"; 
prog_char geschuettelt_string_17[] PROGMEM = "AMPFIELENBER"; 
prog_char geschuettelt_string_18[] PROGMEM = "ENISCHMAFSCHEIL";
prog_char geschuettelt_string_19[] PROGMEM = "WREKGOBERLDG"; 
prog_char geschuettelt_string_20[] PROGMEM = "NNEIRUREWHO"; 
prog_char geschuettelt_string_21[] PROGMEM = "IENWGEBEITABU"; 
prog_char geschuettelt_string_22[] PROGMEM = "BNENEIMARWSCH"; 
prog_char geschuettelt_string_23[] PROGMEM = "ZIBAMDEMER"; 
prog_char geschuettelt_string_24[] PROGMEM = "PALANRKDSCHTFA"; 
prog_char geschuettelt_string_25[] PROGMEM = "ZALSOFFRAKTEL"; 
prog_char geschuettelt_string_26[] PROGMEM = "ENISCHMASCHBEIR"; 
prog_char geschuettelt_string_27[] PROGMEM = "WOSCHLLAFE"; 
prog_char geschuettelt_string_28[] PROGMEM = "MINDIATENMANE";
prog_char geschuettelt_string_29[] PROGMEM = "MILIEELESPFANI"; 
prog_char geschuettelt_string_30[] PROGMEM = "ZANHABDARHN"; 
prog_char geschuettelt_string_31[] PROGMEM = "NNISETTZPLA"; 
prog_char geschuettelt_string_32[] PROGMEM = "EMDAGENHKR"; 
prog_char geschuettelt_string_33[] PROGMEM = "ABGRENILLD"; 
prog_char geschuettelt_string_34[] PROGMEM = "DANWCHTPPEI"; 
prog_char geschuettelt_string_35[] PROGMEM = "KARTINDGEREN"; 
prog_char geschuettelt_string_36[] PROGMEM = "WIEKONENKER"; 
prog_char geschuettelt_string_37[] PROGMEM = "WIREITNEREFNE"; 
prog_char geschuettelt_string_38[] PROGMEM = "NESEIMMSTE";
prog_char geschuettelt_string_39[] PROGMEM = "UNGBEIRSCHTCHER"; 
prog_char geschuettelt_string_40[] PROGMEM = "BATERCKEHAAMS"; 
prog_char geschuettelt_string_41[] PROGMEM = "UNGSCHVEREIZTIEB"; 
prog_char geschuettelt_string_42[] PROGMEM = "ENSCHBRAUREHEZR"; 
prog_char geschuettelt_string_43[] PROGMEM = "TOMKTAREORA"; 
prog_char geschuettelt_string_44[] PROGMEM = "KNROSPEENSO"; 
prog_char geschuettelt_string_45[] PROGMEM = "BRANRMEEUDNGRES"; 
prog_char geschuettelt_string_46[] PROGMEM = "KERWSERWASTFARK"; 
prog_char geschuettelt_string_47[] PROGMEM = "KTALASLEFFORAT"; 
prog_char geschuettelt_string_48[] PROGMEM = "SEIKRFALU";
prog_char geschuettelt_string_49[] PROGMEM = "FFTSOSREAU"; 
prog_char geschuettelt_string_50[] PROGMEM = "STEAUSLLUNG"; 
prog_char geschuettelt_string_51[] PROGMEM = "ENNEEKAFFKAE"; 
prog_char geschuettelt_string_52[] PROGMEM = "LETOHDIRORTEK"; 
prog_char geschuettelt_string_53[] PROGMEM = "STMOREUNDNEG"; 
prog_char geschuettelt_string_54[] PROGMEM = "RUKFAUTNETLAH";
  
       

PROGMEM const char *geschuettelt_string_table[] = 	   // change "geschuettelt_string_table" name to suit
{   
  geschuettelt_string_0,
  geschuettelt_string_1,
  geschuettelt_string_2,
  geschuettelt_string_3,
  geschuettelt_string_4,
  geschuettelt_string_5,
  geschuettelt_string_6,
  geschuettelt_string_7,
  geschuettelt_string_8,
  geschuettelt_string_9,
  geschuettelt_string_10,
  geschuettelt_string_11,
  geschuettelt_string_12,
  geschuettelt_string_13,
  geschuettelt_string_14,
  geschuettelt_string_15,
  geschuettelt_string_16,
  geschuettelt_string_17,
  geschuettelt_string_18,
  geschuettelt_string_19,
  geschuettelt_string_20,
  geschuettelt_string_21,
  geschuettelt_string_22,
  geschuettelt_string_23,
  geschuettelt_string_24,
  geschuettelt_string_25,
  geschuettelt_string_26,
  geschuettelt_string_27,
  geschuettelt_string_28,
  geschuettelt_string_29,
  geschuettelt_string_30,
  geschuettelt_string_31,
  geschuettelt_string_32,
  geschuettelt_string_33,
  geschuettelt_string_34,
  geschuettelt_string_35,
  geschuettelt_string_36,
  geschuettelt_string_37,
  geschuettelt_string_38,
  geschuettelt_string_39,
  geschuettelt_string_40,
  geschuettelt_string_41,
  geschuettelt_string_42,
  geschuettelt_string_43,
  geschuettelt_string_44,
  geschuettelt_string_45,
  geschuettelt_string_46,
  geschuettelt_string_47,
  geschuettelt_string_48,
  geschuettelt_string_49,
  geschuettelt_string_50,
  geschuettelt_string_51,
  geschuettelt_string_52,
  geschuettelt_string_53,
  geschuettelt_string_54
  };

char geschuettelt[255];    // make sure this is large enough for the largest string it must hold


int geschuetteltCounter = 0; // count the used cards of this category
// boolean array to indicate if a card has already been played
boolean geschuetteltUsed[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// variables will change:
boolean buttonState = false;         // variable for reading the pushbutton status
boolean ledStatus = false;           // led status (on or off)
boolean buzzerStatus = false;        // buzzer status (on or off)
int randNumber;                      // random number for the timer
int textrandNumber;                  // random number to pic a 'card'
long int categoryNumber;             // pick a category at random
int timer = 0;                       // the timer
int blinker = 0;                     // flashing LED at the end
int originalDice = 0;                // Dice for original cat. Not start, not end, no matter.
char* catname[]={"Original:", "Bekannt:", "Angesetzt:", "Geschuettelt:"};                        // name of the category
char* place[]={" xxx--", " --xxx", " --xxx--"};                                                  // indicates where to put the sillable in the original cat.
char gameStatus[]={"Game Over"};     // output when all cards of one cat have been played

// run once at programm start
void setup() {
 // initialize Serial connection (use Serial monitor for debuging)
 Serial.begin(9600);
 // initialize the LED pin as an output:
 pinMode(ledPin, OUTPUT);
 // initialize the Buzzer pin as output:
 pinMode(buzzerPin, OUTPUT);
 // initialize the pushbutton pin as an input:
 pinMode(buttonPin, INPUT);
 // feed noise from unconnected pin to random:
 randomSeed(analogRead(5));
 // set up the LCD's number of rows and columns: 
 lcd.begin(16, 2);       
 // set the cursor to column 0, line 0
 lcd.setCursor(0, 0);
 lcd.print("Push Button");
 lcd.setCursor(0, 1);
 lcd.print("to start.");
 
}

// main loop
void loop(){
  // while not all cards of one cat. have been played do the following
  while (originalCounter < 55 || bekanntCounter < 55 || angesetztCounter < 55 || geschuetteltCounter < 55)
  {
    
 // read the state of the pushbutton value:
 buttonState = digitalRead(buttonPin);
 // check if the pushbutton is pressed.
 // if it is, the buttonState is HIGH:
 if (buttonState == HIGH) 
 {
  // change status
  ledStatus = true;
  //debounce button
  delay (400);
 }

  // if the button has been pressed do the following
 if (ledStatus == true) {
  // generate a random number as timer:
  randNumber = random(10, 60);
  // pic a category at random
  categoryNumber = random(4);
  // pic a card at random
  textrandNumber = random(55);
  
      // if the category selection resulted in a 0, "original" is selected
      if (categoryNumber == 0)
     {
       // this checks the boolean array for this cat
       // while there is a 1 (so the card has been played before)
       while (originalUsed[textrandNumber] == 1)
       {
         // look at the next field if it is 0 the card can be played
         textrandNumber++;
         // if the number is >54 we are at the end of the char array
         if (textrandNumber > 54)
         {
           //so we have to start at the beginning
           textrandNumber = 0;
         }
       }
       
       // set the boolean to one (card has been played)
       originalUsed[textrandNumber] = 1;
       // roll the additionl dice for this cat.
       originalDice = random(3);
       // clear display
       lcd.clear();
       // set the cursor to column 0, line 0
       lcd.setCursor(0, 0);
       // print the name of the cat.
       lcd.print(catname[categoryNumber]);
       // read the string from progmem into char
       strcpy_P(original, (char*)pgm_read_word(&(original_string_table[textrandNumber])));
       // set the cursor to column 0, line 1
       // (note: line 1 is the second row, since counting begins with 0):
       lcd.setCursor(0, 1);
       // print card to lcd monitor 
       lcd.print(original);
       // print the choice of the additional dice
       lcd.print(place[originalDice]);
       // count the card
       originalCounter++;
     }

   // if the category selection resulted in a 1, "bekannt" is selected
   else if (categoryNumber == 1)
     {
       // this checks the boolean array for this cat
       // while there is a 1 (so the card has been played before)
       while (bekanntUsed[textrandNumber] == 1)
       {
         // look at the next field if it is 0 the card can be played
         textrandNumber++;
         // if the number is >54 we are at the end of the char array
         if (textrandNumber > 54)
         {
           //so we have to start at the beginning
           textrandNumber = 0;
         }
       }
       
       // set the boolean to one (card has been played)
       bekanntUsed[textrandNumber] = 1;
       
       // clear display
       lcd.clear();       
       // set the cursor to column 0, line 0
       lcd.setCursor(0, 0);       
       // print the name of the cat
       lcd.print(catname[categoryNumber]);
       // read the string from progmem into char
       strcpy_P(bekannt, (char*)pgm_read_word(&(bekannt_string_table[textrandNumber])));
       // set the cursor to column 0, line 0
       lcd.setCursor(0, 1);       
         // print card to lcd monitor 
       lcd.print(bekannt);
         // count the card
       bekanntCounter++;
     }

   // if the category selection resulted in a 2, "angesetzt" is selected
   else if (categoryNumber == 2)
     {
       // this checks the boolean array for this cat
       // while there is a 1 (so the card has been played before)
       while (angesetztUsed[textrandNumber] == 1)
       {
         // look at the next field if it is 0 the card can be played
         textrandNumber++;
         // if the number is >54 we are at the end of the char array
         if (textrandNumber > 54)
         {
           //so we have to start at the beginning
           textrandNumber = 0;
         }
       }
       
       // set the boolean to one (card has been played)
       angesetztUsed[textrandNumber] = 1;
       
       // clear display
       lcd.clear();
       // set the cursor to column 0, line 0
       lcd.setCursor(0, 0);       
       // print the name of the cat
       lcd.print(catname[categoryNumber]);
       // read the string from progmem into char
       strcpy_P(angesetzt, (char*)pgm_read_word(&(angesetzt_string_table[textrandNumber])));
       // set the cursor to column 0, line 0
       lcd.setCursor(0, 1);       
         // print card to lcd monitor 
       lcd.print(angesetzt);
         // count the card
       angesetztCounter++;
     }

   // if the category selection resulted in a 3, "geschuettelt" is selected
   else
     {
       // this checks the boolean array for this cat
       // while there is a 1 (so the card has been played before)
       while (geschuetteltUsed[textrandNumber] == 1 && textrandNumber <= 54)
       {
         // look at the next field if it is 0 the card can be played
         textrandNumber++;
         // if the number is >54 we are at the end of the char array
         if (textrandNumber > 54)
         {
           //so we have to start at the beginning
           textrandNumber = 0;
         }
       }
       
       // set the boolean to one (card has been played)
       geschuetteltUsed[textrandNumber] = 1;
       
       // clear display
       lcd.clear();       
       // set the cursor to column 0, line 0
       lcd.setCursor(0, 0);       
       // print the name of the cat
       lcd.println(catname[categoryNumber]);
       // read the string from progmem into char
       strcpy_P( geschuettelt, (char*)pgm_read_word(&( geschuettelt_string_table[textrandNumber])));
       // set the cursor to column 0, line 0
       lcd.setCursor(0, 1);       
         // print card to lcd monitor 
       lcd.println(geschuettelt);
         // count the card
       geschuetteltCounter++;
     }

   // turn LED on:
  digitalWrite(ledPin, HIGH);
  // ticking of the timer
  // while the time passed is lower than the randomized time:
    for (timer = 0; timer < randNumber; timer++)
    {
      // make a noise
      digitalWrite (buzzerPin, HIGH);
      // wait a short time
      delay (10);
      // turn the noise off (this creates the ticking)
      digitalWrite (buzzerPin,LOW);
      // wait until the next tick starts (10 ms tick + 900 ms wait = one sec. round time)
      delay (900);
    }

  // turn on Buzzer to signal the end of the round:
  digitalWrite(buzzerPin, HIGH);
  // make noise for as long as the LED blinks:
  for (blinker = 0; blinker < 10; blinker++)
    {
      digitalWrite(ledPin, HIGH);
      delay (100);
      digitalWrite(ledPin, LOW);
      delay (100);
    }
  //  delay (1000);
  // turn Buzzer off:
  digitalWrite(buzzerPin, LOW);
  //turn LED off:
  digitalWrite(ledPin, LOW);
 

  // reset everything to wait for the next button press:
  ledStatus = false;
  buttonState = false;
  timer = 0;

// check if 55 cards have been drawn from one category
  }
 }
    // set the cursor to column 0, line 0
    lcd.setCursor(0, 0); 
    lcd.print(gameStatus);
}
