#include "xcint.hpp"

static struct alias_data aliases_array[XC_MAX_ALIASES] =
{
  {"null","No functional",{{"slaterx",0.0}} },
  {"lda","Slater exchange and VWN5 correlation",{{"slaterx",1.0},{"vwn5c",1.0}} },
  {"blyp","Becke exchange and LYP correlation",{{"beckex",1.0},{"lypc",1.0}} },
  {"pbe","PBE exchange and correlation",{{"pbex",1.0},{"pbec",1.0}} },
  {"bp86","Becke-Perdew 1986",{{"beckex",1.0},{"p86c",1.0}} },
  {"kt1","Keal-Tozer 2",{{"slaterx",1.},{"ktx",-0.006},{"vwn5c",1.}} },
  {"kt2","Keal-Tozer 2",{{"slaterx",1.07173},{"ktx",-0.006},{"vwn5c",0.576727}} },
  {"kt3","Keal-Tozer 3",{{"slaterx",1.092},{"ktx",-0.004},{"optxcorr",-0.925452},{"lypc",0.864409}} },
  {"ldaerf","Short-range exchange and correlation LDA functional",{{"ldaerfx",1.0},{"ldaerfc",1.0}}},
  // Hybrid Functionals
  {"pbe0","Perdew-Burke-Ernzerhof",{{"pbex",0.75},{"pbec",1.0},{"exx",0.25}} }, 
  {"b3lyp","Becke-3-paramater-LYP (VWN5 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"lypc",0.81},{"vwn5c",0.19},{"exx",0.20}} }, 
  {"m06","M06", {{"m06c",1.0},{"m06x",1.0}} }, 
  {"m06-2x","M06 2X", {{"m06x2c",1.0},{"m06x2x",1.0}} }, 
  {"m06L","M06 L", {{"m06lc",1.0},{"m06lx",1.0}} }, 
  {"b3lyp-g","Becke-3-paramater-LYP (VWN3 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"lypc",0.81},{"vwn3c",0.19},{"exx",0.20}} }, 
  {"b3p86","Becke-3-paramater-LYP (VWN5 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"p86corrc",0.81},{"vwn5c",1.0},{"exx",0.20}} }, 
  {"b3p86-g","Becke-3-paramater-LYP (VWN3 form)", {{"slaterx",0.80},{"beckecorrx",0.72},{"p86corrc",0.81},{"vwn3c",1.0},{"exx",0.20}} }, 
  {"bpw91","Becke 88 exchange+PW91",{{"beckex",1.0},{"pw91c",1.0}} },
  {"b97","B97 exchange and correlation", {{"b97x",1.0},{"b97c",1.0},{"exx",0.1943}} },
  {"b97-1","B97-1 exchange and correlation", {{"b97_1x",1.0},{"b97_1c",1.0},{"exx",0.21}} },
  {"b97_2","B97-2 exchange and correlation", {{"b97_2x",1.0},{"b97_2c",1.0},{"exx",0.21}} },
  {"camb3lyp","CAM-B3LYP",{{"cam_alpha",0.19},{"cam_beta",0.46},{"rangesep_mu",0.33},{"beckecamx",1.0},{"vwn5c",0.19},{"lypc",0.81},{"exx",1.0}} },
  // Some of these are there to match the names used in Dalton
  {"vwn","VWN5 correlation",{{"vwn5c",1.0}}},
  {"vwn5","VWN5 correlation",{{"vwn5c",1.0}}},
  {"vwn3","VWN5 correlation",{{"vwn3c",1.0}}},
  {"svwn","Slater exchange and VWN5 correlation",{{"slaterx",1.0},{"vwn5c",1.0}} },
  {"svwn5","Slater exchange and VWN5 correlation",{{"slaterx",1.0},{"vwn5c",1.0}} },
  {"svwn3","Slater exchange and VWN3 correlation",{{"slaterx",1.0},{"vwn3c",1.0}} },
  {"becke","Becke exchange",{{"beckecorrx",1.0}}},
  {"slater","Slater exchange",{{"slaterx",1.0}}},
  {"olyp","LYP correlation and OPTX exchange",{{"lypc",1.0},{"optx",1.0}}},
  {"lyp","LYP correlation",{{"lypc",1.0}}},
  // ADMM exchange funtional corrections
  {"B88X","Becke exchange",{{"slaterx",1.},{"beckecorrx",1.0}} },
  {"LDAX","Slater exchange",{{"slaterx",1.}} },
  {"PBEX","PBE exchange",{{"pbex",1.0}} },
  {"KT3X","Keal-Tozer 3 exchange",{{"slaterx",1.092},{"ktx",-0.004},{"optxcorr",-0.925452}} },
  {"OPTX","OptX exchange",{{"slaterx",1.05151},{"optxcorr",-1.43169}} },
  {"camcompx","Complementary part of CAM exchange",{{"beckex",1.0},{"beckecamx",-1.0},{"cam_alpha",0.19},
						    {"cam_beta",0.46},{"rangesep_mu",0.33}}},
  //Kinetic energy corrections for orbital free DFT
  {"tfk","Thomas-Fermi corraction to be put in effective potential.",{{"tfk",1.0}} },
  {"tw","von Weizsacker corraction to be put in effective potential.",{{"tw",1.0}} },
};



struct alias_data *xcint_aliases = aliases_array;
