/* 
Universidade Federal de Rondonia
Ciencia da Computacao
Computacao Grafica
Academica: Thania Beatriz

 */

#include <GL/gl.h>
#include <GL/freeglut.h>


#include <windows.h>
#include <stdio.h>
#include "tgaload.h"

// Qtd m?xima de texturas a serem usadas no programa
#define MAX_NO_TEXTURES 10

#define TEXT_SOL 0
#define TEXT_LUA 1
#define TEXT_TERRA 2
#define TEXT_MARTE 3
#define TEXT_MERCURIO 4
#define TEXT_VENUS 5
#define TEXT_JUPITER 6
#define TEXT_SATURNO 7
#define TEXT_URANO 8
#define TEXT_NETUNO 9

static GLfloat xAxis[] = {-0.685110,0.648940,3.179407,-2.393558,5.452399,-2.901516,-1.483730,-5.589639,-2.785849,4.894033,4.379944,-2.380775,-0.606152,4.061940,-4.365272,-2.041221,1.927577,-2.920128,-1.623491,-4.750216,2.639456,-2.806899,5.267063,3.935562,3.287027,-3.989747,-1.690884,2.806082,0.819092,-0.107787,-5.387106,0.833050,-1.391898,5.537064,-2.384970,1.026479,-1.375171,-0.807031,-5.533073,0.729153,1.717874,-4.916106,-5.873425,2.360545,-4.375246,0.046590,-2.484068,1.020554,1.478208,1.315712,2.988755,-5.364832,-4.444184,3.016761,4.984243,-0.777094,0.084797,0.799228,5.298508,-5.812198,5.855350,4.952457,0.782659,1.085694,-0.255566,2.761641,4.443291,-2.210529,-2.468330,0.096922,-3.223363,-3.059615,-0.565852,5.516133,0.021137,-3.429645,2.870231,-4.618427,5.694236,5.779136,2.088578,-2.589037,5.002126,-1.962445,-5.748139,-3.238548,-6.006032,1.881174,-5.160710,6.048765,-0.506207,-5.696618,0.763258,-2.107385,-6.418202,0.589595,-3.743751,2.949693,1.780330,1.866774,3.010785,-3.989041,-2.648382,-3.340885,5.650560,2.381362,0.716379,2.094454,-5.354286,1.896787,-0.253012,6.060381,3.159684,-0.436074,-4.744577,-6.147179,6.180134,-2.089556,-2.502154,6.181229,0.750754,1.774364,-0.297573,2.073885,1.189200,-1.950441,3.959147,2.011511,-5.244400,-3.562038,1.157298,5.106328,2.896655,5.122875,0.640035,-4.388454,3.641551,-5.977352,2.946994,0.835327,-0.626470,3.622417,2.874710,-2.992469,6.481830,-2.237552,3.512307,-0.673091,-0.271870,0.416163,1.310432,-0.813020,-6.284650,6.315063,5.837972,-6.310421,-4.583751,5.320312,3.998471,-1.423023,-0.169397,-5.167040,6.463736,-5.231009,-5.741961,-4.026683,6.259658,5.649985,3.216403,4.715251,4.451168,-1.873772,4.119334,-0.171055,4.024181,0.836808,1.197871,-2.266822,2.635873,4.221767,5.476511,0.848336,2.371007,4.592949,3.760247,-1.389506,0.444281,3.793255,2.617420,-4.146334,-2.276571,-0.869029,-0.582015,-2.452248,-2.693502,-1.094147,-3.916558,3.295572,-3.315464,1.674992,5.941185,4.487695,-5.766397,-6.308557,5.613599,0.602300,-4.219771,4.080800,0.210182,0.327486,0.017179,2.011564,1.099336,3.684714,3.776326,-2.298788,5.504915,-3.519362,-1.015532,0.275568,-4.063554,-0.921193,5.637878,4.947741,5.024302,-4.205155,5.345203,0.552687,-1.312598,5.265560,3.875377,0.891788,-3.939996,-3.938355,0.061629,-0.683052,3.356998,-5.708304,2.444104,0.412753,3.320715,-0.645271,3.419758,-3.587247,5.910081,6.465704,-5.769683,4.420299,-0.711922,5.923491,5.591084,-0.104736,-1.040985,-3.259765,2.950773,-1.538743,4.566692,6.288508,-0.913243,-6.198452,-4.869370,5.508064,2.009177,-2.536551,-1.978237,-4.355188,1.642278,5.777559,-4.303028,0.798590,1.802778,4.649904,-3.410179,-3.588207,6.172163,2.510816,-4.950038,-6.329474,3.873132,-5.287381,-3.096062,2.328585,-2.817387,-1.272715,-1.611145,2.744128,-5.450695,2.724118,2.591492,-1.351353,-4.222192,4.790606,1.575062,5.042518,0.741032,-5.899285,1.796172,6.474894,2.298108,0.813073,-6.340919,-5.248827,5.981429,5.783720,6.413919,-1.141461,-1.669634,6.070105,2.347974,0.349864,-0.398008,-0.943428,2.798297,5.678937,-2.396770,-3.678607,5.394430,0.268828,-2.896200,0.406176,-2.381936,-2.031404,-5.446632,6.418299,-0.711698,3.670385,-3.544824,1.042444,-3.707212,-5.660213,-1.093323,6.006888,6.225828,6.049475,4.021283,4.650871,0.609110,1.111942,5.838863,5.329073,-0.314567,-2.855036,-2.033915,-3.088947,-6.037150,6.212579,-5.465881,3.567425,-4.673634,0.064257,4.401740,-4.860361,-0.348233,2.240693,-2.608676,-2.367804,-1.337960,1.336555,5.037101,-3.797185,-1.188627,5.872134,-6.335507,3.518950,-2.605624,-4.695264,5.986773,-4.710717,2.858126,2.884632,4.487111,-1.702088,-0.885060,-5.999276,3.907219,4.258205,4.461171,6.247014,-4.824267,6.337384,-3.818564,0.513297,-1.834185,1.222421,3.304742,5.549615,5.265208,3.153620,-5.785114,-1.430076,5.872223,4.639705,3.001660,5.896534,-5.780723,4.210985,-4.217131,-4.761501,-1.134467,6.441899,-2.497467,-4.530566,4.058925,5.298249,4.607458,-2.731783,4.243574,6.140949,5.982623,1.853338,3.452981,0.447675,3.019154,-4.495229,3.435367,4.954855,-0.729101,3.288636,4.803983,-3.113551,3.163955,-0.819994,1.291132,-2.867534,4.701403,4.396088,-2.079826,6.113244,-4.765415,2.494534,-5.725197,-2.832788,4.794218,-4.751539,-2.854833,-2.449708,-4.686520,1.489609,-6.004264,-6.052237,-2.386209,2.592634,-0.569608,2.128271,-1.908501,1.650334,-6.452865,-3.968241,-2.402345,3.355852,-4.246674,-1.758837,0.359279,5.992591,5.170241,-3.911913,6.247427,-5.452315,-2.254299,-4.293921,1.350000,-0.594876,5.724982,2.260881,1.940595,-5.567527,1.385829,-5.507975,5.717139,-3.969109,1.550925,1.836155,-2.724950,-2.596933,-6.152525,-4.112454,-5.978840,0.065282,0.687472,-4.831562,1.196586,-1.124164,3.785024,0.078270,-2.444383,2.045285,-0.877248,5.082977,4.949636,-4.936373,3.296629,-2.863483,-5.955376,-4.104752,-6.371354,-1.046768,1.069784,5.887061,4.091896,-0.635874,-5.512213,-1.816202,-3.605479,2.501793,2.632913,-2.856246,4.568390,0.973358,-1.808275,4.236145,-2.122164,-1.844631,4.495553,-3.355501,6.264438,4.813911,3.004680,5.273798,2.729282,4.951243,-4.681500,-5.891175,1.523723,-5.700729,-2.698585,-4.652669,0.906427,-4.195107,0.632518,3.085554,-3.783843,-2.026155,1.818238,-4.340044,2.825323,4.211767,2.434168,-5.240446,-4.930921,-4.409890,3.074282,5.535145,4.427547,-1.940889,-0.445082,-0.381551,-5.684970,-0.716738,6.391894,-2.864854,-6.428066,-2.387483,2.412231,4.531765,1.718390,2.542636,-1.404354,5.316035,3.321884,-5.921795,0.621040,-6.434546,2.663776,3.058924,4.245830,2.698703,3.096156,-3.763025,-6.281401,4.724806,-0.530509,-3.423914,-2.676366,-1.151052,4.996988,-1.878103,5.205447,-1.150017,1.485828,3.013432,3.507365,-1.799095,1.840213,-5.889226,5.839241,5.290042,-6.035723,0.436972,6.451258,2.082869,-5.660455,-4.690761,-0.445758,-3.352494,0.286539,0.972219,0.174701,-6.094534,2.608666,-2.064304,0.607512,0.956381,-5.991282,-4.934757,-1.850928,3.525606,2.694378,-1.353329,-2.759461,1.723948,0.662249,4.856983,-5.108613,2.408913,-0.664438,5.904099,4.431652,-2.770442,1.859720,-2.249568,-1.936175,-3.511218,4.262516,2.698913,-1.232355,1.658494,0.031466,-1.428145,-2.652119,-6.482143,0.539974,4.826352,-0.028055,-0.389758,5.838202,-0.566871,4.929435,-3.413686,-4.094691,0.050139,-5.044193,-3.087931,-3.957094,-1.021378,-0.414765,1.498201,-2.789012,-4.712613,-2.092865,1.352682,3.704697,5.391873,4.996645,3.654806,4.444335,-4.553447,-0.194384,-3.924083,5.278835,5.943428,3.968421,-1.632405,6.179296,4.430048,6.486320,3.615778,0.304292,-0.695294,-0.799229,-1.513514,1.344617,-0.580956,4.857162,-1.370123,-3.634012,-4.501023,0.647290,3.781569,-0.306987,-2.964810,-6.200921,3.174874,-1.168210,-3.384885,-0.634467,-5.102665,1.154299,-3.475325,-3.186373,-4.456478,-1.801405,5.648219,-5.982306,4.676782,-0.602029,0.916122,-2.285742,-1.304402,-3.763321,-2.893175,5.100688,3.309509,-3.861790,-6.095810,-0.921844,2.440078,1.389970,5.630799,6.050000,5.958855,-3.921096,-1.213313,2.901545,4.518847,-4.956255,1.788597,-3.429361,0.723363,4.857164,-3.108481,1.293981,-2.457372,3.674622,0.184967,4.829798,-1.227392,-2.077137,-1.889157,5.792759,-3.334182,3.942117,5.736269,-5.307432,4.561038,0.757298,-1.143446,-1.832987,-0.939888,-5.381750,5.359391,-0.081477,-2.231323,4.458300,1.456496,-3.070554,-1.384730,-1.790166,4.553051,-0.466340,-5.961881,4.351455,-5.588904,-4.540430,-4.550658,4.248910,-2.679975,1.698092,6.366279,2.580885,-4.406757,0.171155,-4.402741,-6.043882,-5.336187,5.668510,-2.743910,-4.478867,-5.984436,-0.212525,-3.441863,2.058691,3.645277,-2.811008,-0.160457,1.270836,-0.691669,3.619747,-0.966645,-5.105456,-3.862051,-2.342089,-4.118173,0.137661,-1.815002,-4.086378,1.234808,-3.818079,1.226264,-4.588691,-4.887031,-5.328954,-5.017238,-1.488957,0.977849,-6.495793,-5.440057,-0.341143,-2.277450,3.494272,-3.247873};
static GLfloat yAxis[] = {-3.437696,-0.393137,2.275572,-0.525745,-0.752470,-0.539106,-4.120825,-3.461494,-2.687078,0.840140,2.181875,0.893124,-4.158798,1.780657,0.035728,1.781398,-3.200376,-4.346865,0.868660,-0.267518,-2.579694,1.617660,-1.724699,-1.656882,-1.446919,3.970052,-0.801136,-0.588522,0.717614,3.551633,3.012651,2.605196,-1.200882,2.009009,-0.608109,-3.696834,3.943151,-1.802605,0.008207,3.357611,0.242658,-3.328076,2.102422,-0.703440,3.531081,3.335552,0.980862,-2.662555,1.588160,0.090855,-1.803128,-4.743140,-3.517510,-4.882908,1.111065,-2.520128,-2.249068,-2.959005,1.801837,0.186827,1.518229,0.260515,-3.108436,-4.697735,-4.842837,-1.580156,3.620812,0.090998,2.626438,-0.333545,-3.173501,-4.104538,2.973753,-1.348430,3.648265,1.162851,3.197618,-0.042628,2.051100,3.146857,0.626680,-4.227955,0.252417,-1.660181,1.047718,3.214033,1.546037,1.507060,-1.330912,3.320551,0.604859,-4.933587,-4.263476,-2.012547,0.680674,1.074603,-4.749974,-0.309912,0.903493,0.983614,-3.384593,-4.179409,3.008219,-1.297978,1.029218,-3.714312,-0.325810,-1.500248,-2.860620,-2.898121,-0.923279,1.986856,1.102455,-2.147727,-0.285235,-2.429114,-1.109878,-1.224184,-4.980338,-4.650568,3.481753,3.812264,-0.498527,-3.863059,-3.608153,0.345880,3.012091,1.752083,-3.065452,0.370060,1.308915,0.929047,2.958929,-3.202482,-2.999276,2.719104,-1.634830,1.372086,-0.994334,0.803898,2.413126,-1.693772,-0.983680,-3.052726,-0.368560,1.507420,-0.099737,3.823729,-3.997832,3.460311,1.238309,-2.653843,0.624845,-0.095984,-1.175319,1.098672,0.139965,-4.026500,-2.658885,-2.020571,-4.559391,1.398192,3.998693,-0.881281,-3.562970,-4.758867,-2.432942,-1.754028,3.335518,2.260178,3.234105,0.987621,0.835505,1.103165,-4.765083,-4.145587,2.255921,-2.064004,2.567896,0.347223,2.827217,-4.160959,-2.789840,2.878336,-2.524965,-3.651974,-0.891745,2.304144,-2.070638,2.163413,-4.463074,2.840132,-1.994531,-3.911646,1.019784,-1.500589,1.347744,3.891085,-4.588002,-4.244528,-1.348904,-1.031903,2.543110,1.255947,0.383735,2.050416,-1.923921,-3.865920,3.620058,-0.949136,3.644545,1.926637,-1.865491,-3.160417,2.026032,-3.526664,-4.577488,1.582863,-3.676825,-1.137247,3.216052,-0.405267,-3.923680,0.008922,-1.915256,2.150572,-3.225140,-3.675905,-4.586211,-3.317482,-2.504957,1.633918,2.361238,-2.251694,-0.436732,3.919296,-2.220374,2.998491,-1.636000,-2.891816,-3.302129,-3.715953,-4.055925,1.907300,2.603640,-4.804461,0.023585,1.057257,-4.197812,-0.753450,-2.971806,1.748644,-3.399296,3.293091,1.033622,3.583068,-4.079864,-3.126551,2.942850,1.637149,3.172051,2.119161,1.158659,2.832126,-3.566948,-3.550588,3.237900,-0.186900,0.710632,2.934950,0.022581,-3.054744,-2.320123,-0.778663,-2.139996,3.020662,-2.015259,3.798658,-3.297159,-3.504956,-2.111521,-0.548331,0.073931,2.412600,0.110101,0.699833,1.381711,1.235830,-1.073550,0.972194,0.271856,-0.106523,3.625460,0.913844,-3.329050,3.167670,-2.992535,0.685396,-3.280520,-4.620115,3.136536,3.139614,0.188219,-4.403273,3.105425,-2.692342,1.628105,2.645298,-0.567583,-1.344103,-3.211514,-3.084622,0.294569,0.597078,-4.945248,2.508702,-1.978672,-3.851267,-1.695136,2.154326,-0.966468,-4.707197,-0.476914,-4.514337,-3.779726,-2.825621,-3.079598,-1.604789,-4.190510,2.429882,-2.781319,-2.559511,0.515036,-0.757289,3.600453,0.247911,-4.896081,-4.430053,-3.720901,-1.596853,-0.922696,1.629450,0.053652,-0.045578,-3.403043,-0.455150,-1.398845,0.288706,-2.644439,0.127212,-4.645269,-0.382945,3.498793,3.057325,-1.889110,1.990543,-1.723087,3.046411,0.074562,-2.629844,-2.356976,-3.043093,-1.864809,-0.991322,3.022108,1.032292,-2.931343,3.981894,-1.366868,-0.084679,2.024151,-1.439227,-3.260129,0.320098,-3.733875,-3.825786,0.750914,1.206363,-4.803370,2.954897,3.550113,3.854386,1.756078,-2.505653,-0.240788,0.958553,2.593005,-3.634712,-0.948752,1.571313,-1.340460,3.278026,3.505589,-3.091325,-3.777895,-3.140705,0.852881,-2.573306,2.601044,-3.175997,-0.495675,3.897773,-4.478551,0.142972,1.117142,-0.472166,-2.362977,3.619207,3.535040,0.829511,3.855574,-0.201809,0.126236,1.080375,-0.996057,-2.631177,1.568980,-1.865584,-1.047046,1.432578,-3.434947,-4.359060,-3.340707,3.151628,2.722289,-1.314134,2.591008,-1.961590,-3.172588,0.114992,-4.718951,0.343157,-0.311930,3.442456,0.832262,-3.043544,-4.310481,-1.353115,0.865414,-0.795220,2.235259,1.855348,3.773637,-3.197611,3.486868,-0.698798,-2.109576,-1.799747,-1.415249,-2.592770,3.761044,2.434671,-0.867442,3.868766,-0.794691,-1.460439,-1.193696,-0.268829,2.781895,-2.277388,-0.073420,-4.556139,-3.832589,-4.035903,1.468219,-0.835158,0.697770,-2.527065,-3.213384,-2.214521,2.703556,-0.076869,-4.921087,-3.888846,-3.682348,1.248089,0.646242,-1.947564,3.075831,-2.196299,0.942821,2.461905,-2.628111,-2.856448,1.193155,-4.130892,-2.322179,2.081813,2.966632,3.912009,-0.287521,0.582728,-3.183035,-4.972870,-0.629375,2.006258,-4.174823,1.290550,2.008073,-2.736625,2.169534,-0.311333,2.942355,-1.240470,-0.248268,-0.424078,-1.122519,1.532972,0.104335,-2.382137,-2.758351,-1.861437,2.918344,3.931261,-3.901202,1.958608,0.945563,2.961304,1.354296,-0.798930,-1.660699,-4.209811,0.639199,0.564243,3.679660,2.479189,-4.862771,-0.126649,-3.539531,0.927013,0.022401,-0.416792,2.764806,-4.073359,0.538693,-3.908657,2.966439,-2.906323,0.329100,-3.620853,0.620932,-1.762923,-1.255429,1.078164,-1.933603,-3.897764,-1.872088,2.461709,-2.079271,-1.200152,-1.000680,0.473835,-3.064209,-1.447671,-3.052600,1.743716,0.386624,2.828170,-2.168848,2.543973,-2.648829,1.753310,1.387196,2.316196,-3.146428,-0.750265,0.832614,-3.173597,2.905431,-4.264217,-0.762639,0.444003,-0.937987,2.000275,-2.132910,1.009544,-0.347011,3.906705,-1.993513,-2.147437,-3.300294,2.629287,-0.195370,-4.873973,-3.386371,1.958342,2.740562,-4.477112,-3.031562,-4.305458,-3.587075,-1.627258,1.036465,-0.642395,-1.909654,-2.834889,-3.415933,1.152275,-3.189689,-1.715236,1.349705,-4.516051,0.150947,3.413112,1.977332,-4.863650,-1.271914,1.491332,-1.258744,-1.141779,1.772676,-2.518731,0.742994,1.946367,-2.479753,-1.416077,-1.357873,1.488076,2.502628,-0.892560,-0.422823,2.563984,-3.354993,-1.628637,-2.698722,-3.457393,3.870233,3.469289,0.119830,-1.795837,-4.173398,-2.766866,2.136644,-0.342861,0.607246,-3.206982,-1.365548,1.021441,-0.542781,-1.672805,3.833250,-4.778093,1.322303,-1.677504,-3.757261,-1.316746,-1.251206,-3.628464,-0.520379,1.670035,2.964864,2.599462,-1.473915,3.417672,-2.440343,-1.235606,-2.888181,1.004182,-4.965637,-4.980580,-3.022510,-1.714289,2.299522,-2.966980,1.590313,-0.854583,1.328406,3.497990,-3.891462,1.787307,1.455956,1.053882,-2.899606,-3.477908,-0.221034,0.820896,-0.712101,1.512393,-4.229187,-2.967505,-2.565494,0.465912,-0.215910,-4.418327,-1.407288,-0.900845,2.455691,-2.329256,-3.543248,2.182194,-4.679632,-3.979931,-4.355515,3.044456,-4.904357,-3.699666,1.730741,-3.384950,0.247445,3.527084,-3.993732,-4.767972,-1.053260,-1.775828,0.925597,-4.258317,1.434886,-3.789844,0.135627,2.434914,-1.122671,2.522184,-1.147286,1.853912,2.609341,-2.208330,-0.995333,-2.230316,-3.214017,2.728148,-3.195149,-3.841681,2.953500,-2.481342,-1.107530,0.107575,3.410850,-3.799932,-0.143812,3.290183,3.467882,2.281250,2.584914,1.115614,-4.694762,0.749742,0.380100,-1.209666,-3.601557,-3.169992,2.726880,2.186246,3.694912,2.120022,-3.755095,-2.854419,3.695318,1.755656,3.993599,2.463895,-1.108451,-2.161065,1.189200,1.077412,-1.267237,-3.350361,3.502004,-2.951508,3.919573,2.838768,0.182595,-2.732179,1.881970,-1.465468,-1.971309,2.122681,-4.545434,0.653174,-3.885105,-1.933644,3.475231,0.211058,-4.424024,-2.115360,2.475191,2.499955,1.504917,-1.514198,-0.204791,-2.668655,-3.469249,-0.609594,-0.851660,-4.636851,-0.459758,1.584746,3.226044,-2.439329,3.570921,0.669948,-0.029739,-3.334861,3.611472,1.548235,-1.069313,1.304150,-0.443202,2.271254,0.478518,-2.522816};



// vetor com os n?meros das texturas
GLuint texture_id[MAX_NO_TEXTURES];


/* angulos de rotacao para os corpos celestes */
float anguloTerra = 0;
float anguloLua = 0;
float anguloMarte = 0;
float anguloMercurio = 0;
float anguloVenus = 0;
float anguloJupiter = 0;
float anguloSaturno = 0;
float anguloUrano = 0;
float anguloNetuno = 0;

int bigOrbitActive = 1;


/* para a camera, lembrem-se dos exercicios anteriores */
#define y_min 60
#define ro_min 120
float eyex = 0;
float eyey = y_min;
float eyez = ro_min;

int xrot;
int yrot;
int zrot;
float ratio;
int bot, rotX_ini, rotY_ini, x_ini, y_ini;

// **********************************************************************
//  void initTexture(void)
//		Define a textura a ser usada 
//
// **********************************************************************
void initTexture (void){

	// Habilita o uso de textura 
	glEnable (GL_TEXTURE_2D);

	// Define a forma de armazenamento dos pixels na textura (1= alihamento por byte)
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	// Define quantas texturas ser?o usadas no programa 
	glGenTextures (10, texture_id);  // num texturas;
									// texture_id = vetor que guardas os n?meros das texturas

	// Define o n?mero da textura do cubo.
	texture_id[TEXT_SOL] = 10;
	texture_id[TEXT_LUA] = 20;
	texture_id[TEXT_TERRA] = 30;
	texture_id[TEXT_MARTE] = 40;
	texture_id[TEXT_MERCURIO] = 50;
	texture_id[TEXT_VENUS] = 60;
	texture_id[TEXT_JUPITER] = 70;
	texture_id[TEXT_SATURNO] = 80;
	texture_id[TEXT_URANO] = 90;
	texture_id[TEXT_NETUNO] = 100;



	image_t temp_image;

	// Define que tipo de textura ser? usada
	// GL_TEXTURE_2D ==> define que ser? usada uma textura 2D (bitmaps)
	// texture_id[CUBE_TEXTURE]  ==> define o n?mero da textura 
	
	// sol
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_SOL]);
	tgaLoad  ("sol.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//mercurio
	
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_MERCURIO]);
	tgaLoad  ("mercurio.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//venus
	
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_VENUS]);
	tgaLoad  ("venus.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//lua
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_LUA]);
	tgaLoad  ("lua.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//terra
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_TERRA]);
	tgaLoad  ("terra.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//marte
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_MARTE]);
	tgaLoad  ("marte.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//jupiter
	
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_JUPITER]);
	tgaLoad  ("jupiter.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//saturno
	
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_SATURNO]);
	tgaLoad  ("saturno.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//urano
	
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_URANO]);
	tgaLoad  ("urano.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	//netuno
	
	glBindTexture (GL_TEXTURE_2D, texture_id[TEXT_NETUNO]);
	tgaLoad  ("netuno.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY);
	
	 //Habilita/gera o uso de textura nas esferas
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    // GL_TEXTURE_2D ==> define que sera usada uma textura 2D (bitmaps)
    glEnable(GL_TEXTURE_2D);
}

// **********************************************************************
//  void init(void)
//		Inicializa os par?metros globais de OpenGL
//
// **********************************************************************
void init(void){
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glEnable ( GL_COLOR_MATERIAL );
	glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	
	glEnable ( GL_CULL_FACE );
	
}

// **********************************************************************
//  void reshape( int w, int h )
//		trata o redimensionamento da janela OpenGL
//
// **********************************************************************
void reshape( int w, int h ){
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(80,ratio,1,200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 30,
		      0,0,10,
			  0.0f,1.0f,0.0f);
}

/* Hierarquia do Sistema Solar 

Sol -
	Mercurio                ok
	Venus					ok
	Terra [lua]             ok
	Marte                   ok
	Jupiter		            ok
	Saturno					ok
	Urano				    ok	
	Netuno                  ok
	
	

*/

void desenhaSol(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_SOL]);
	glutSolidSphere( 20, 16, 16 );

}

void desenhaMercurio(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_MERCURIO]);
	glutSolidSphere( 4, 16, 16 );

}


void desenhaVenus(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_VENUS]);
	glutSolidSphere( 4, 16, 16 );

}

void desenhaTerra(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_TERRA]);
	glutSolidSphere( 5, 16, 16 );

}

void desenhaLua(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_LUA]);
	glutSolidSphere( 1, 16, 16 );

}

void desenhaMarte(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_MARTE]);
	glutSolidSphere( 4, 16, 16 );

}

void desenhaJupiter(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_JUPITER]);
	glutSolidSphere( 8, 16, 16 );

}

void desenhaSaturno(){
	
	glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_SATURNO]);

    glutSolidSphere( 10, 16, 16);
    glRotatef(60, 1, 0, 0);
    glutSolidTorus( 5, 20, 2, 20);
}

void desenhaUrano(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_URANO]);
	glutSolidSphere( 4, 16, 16 );

}

void desenhaNetuno(){

    glBindTexture(GL_TEXTURE_2D, texture_id[TEXT_NETUNO]);
	glutSolidSphere( 4, 16, 16 );

}

void criaEstrelas(){

    glPushMatrix();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(0.3f,-0.6f);
		glVertex2f(0.4f,-0.6f);
		glVertex2f(0.35f,-0.5f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(0.3f,-0.55f);
		glVertex2f(0.4f,-0.55f);
		glVertex2f(0.35f,-0.65f);
	glEnd();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(-0.3f,-0.6f);
		glVertex2f(-0.4f,-0.6f);
		glVertex2f(-0.35f,-0.5f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(-0.3f,-0.55f);
		glVertex2f(-0.4f,-0.55f);
		glVertex2f(-0.35f,-0.65f);
	glEnd();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(3.2f,3.1f);
		glVertex2f(3.3f,3.1f);
		glVertex2f(3.25f,3.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(3.2f,3.16f);
		glVertex2f(3.3f,3.16f);
		glVertex2f(3.25f,3.05f);
	glEnd();
		
	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(-3.2f,3.1f);
		glVertex2f(-3.3f,3.1f);
		glVertex2f(-3.25f,3.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(-3.2f,3.16f);
		glVertex2f(-3.3f,3.16f);
		glVertex2f(-3.25f,3.05f);
	glEnd();
	
	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(3.2f,-3.1f);
		glVertex2f(3.3f,-3.1f);
		glVertex2f(3.25f,-3.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(3.2f,-3.16f);
		glVertex2f(3.3f,-3.16f);
		glVertex2f(3.25f,-3.05f);
	glEnd();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(2.2f,-2.1f);
		glVertex2f(2.3f,-2.1f);
		glVertex2f(2.25f,-2.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(2.2f,-2.16f);
		glVertex2f(2.3f,-2.16f);
		glVertex2f(2.25f,-2.05f);
	glEnd();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(2.2f,-2.1f);
		glVertex2f(2.3f,-2.1f);
		glVertex2f(2.25f,-2.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(2.2f,-2.16f);
		glVertex2f(2.3f,-2.16f);
		glVertex2f(2.25f,-2.05f);
	glEnd();
	
	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(5.2f,-2.1f);
		glVertex2f(5.3f,-2.1f);
		glVertex2f(5.25f,-2.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(5.2f,-2.16f);
		glVertex2f(5.3f,-2.16f);
		glVertex2f(5.25f,-2.05f);
	glEnd();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(-5.2f,-2.1f);
		glVertex2f(-5.3f,-2.1f);
		glVertex2f(-5.25f,-2.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(-5.2f,-2.16f);
		glVertex2f(-5.3f,-2.16f);
		glVertex2f(-5.25f,-2.05f);
	glEnd();
	glPopMatrix();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(-5.2f,2.1f);
		glVertex2f(-5.3f,2.1f);
		glVertex2f(-5.25f,2.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(-5.2f,2.16f);
		glVertex2f(-5.3f,2.16f);
		glVertex2f(-5.25f,2.05f);
	glEnd();

	glBegin(GL_TRIANGLES); 
		glColor3f(1.0f, 1.0f, 1.0f); // Blue
		glVertex2f(-4.2f,3.1f);
		glVertex2f(-4.3f,3.1f);
		glVertex2f(-4.25f,3.2f);
		glColor3f(1.0f, 1.0f, 1.0f); // Red
		glVertex2f(-4.2f,3.16f);
		glVertex2f(-4.3f,3.16f);
		glVertex2f(-4.25f,3.05f);
	glEnd();
	glPopMatrix();
}

void luzSol(void){
    GLfloat LuzSolar[4] = {0.2, 0.2, 0.2, 1.0};
    GLfloat posicaoLuz[4] = {0.0, 0.0, 0.0, 1.0};

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzSolar);
    glLightfv(GL_LIGHT0, GL_AMBIENT, LuzSolar);

    // Especularidade dos planetas
    GLfloat especularidade[4]={1.0, 1.0, 1.0, 1.0};
    GLint especMaterial = 60;

    //Reflet?ncia dos planetas e a concentra??o de luz
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

}



void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
	gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);
	    	
	   	glPushMatrix();
			glBegin(GL_POINTS);
				glColor3f(1.0,1.0,1.0);
				glPointSize(10.0);
				for(int i=0;i<800;i++){
				//	float x = xAxisRandomNumberGenerator();
				//	float y = yAxisRandomNumberGenerator();
					glVertex2f(xAxis[i],yAxis[i]);	
				//	glVertex2f(x,y);	
				}
			/*	glVertex2f(6.5, 4.0);
				glVertex2f(-6.5, 4.0);
				glVertex2f(-6.5, -5.0);
				glVertex2f(6.5, -5.0);
				glVertex2f(-4.0, -3.0);
				glVertex2f(-4.0, -3.0);
				glVertex2f(-4.0, -3.0);
				glVertex2f(-4.0, -3.0); */
			glEnd();
			criaEstrelas();


    glPushMatrix();
	  desenhaSol();
		  glPushMatrix();
		  
  		    glRotatef( anguloMercurio, 0, 1, 0 );
  		    glTranslatef( 40, 0, 0 );
  	 		 desenhaMercurio();
  	   	 	  glPopMatrix();

  		glRotatef( anguloVenus, 0, 1, 0 );
  		    glTranslatef( 30, 0, 0 );
  	 		 desenhaVenus();
  	   	 	  glPopMatrix();

	 	 glPushMatrix();
  		  glRotatef( anguloTerra, 0, 1, 0 );
  		  glTranslatef( 50, 0, 0 );
  		  
  	  desenhaTerra();
  		  glPushMatrix();
  		    glRotatef( anguloLua, 0, 1, 0 );
  		    glTranslatef( 7, 0, 0 );
  		    
      desenhaLua();
 	 	  glPopMatrix();
 		 glPopMatrix();
 	 glPushMatrix();
 	 
 		   glRotatef( anguloMarte, 0, 1, 0 );
 		   glTranslatef( 60, 0, 0 );   
 	   desenhaMarte();
 	 glPopMatrix();
 	 
 	 glPushMatrix();
 	 
 		   glRotatef( anguloJupiter, 0, 1, 0 );
 		   glTranslatef( 75, 0, 0 );   
 	   desenhaJupiter();
 	 glPopMatrix();

	glPushMatrix();
          glRotatef( anguloSaturno, 0, 1, 0); 
          glTranslatef( 110, 0, 0);
          desenhaSaturno();
	glPopMatrix();
 	 
 	glPushMatrix();
          glRotatef( anguloUrano, 0, 1, 0); 
          glTranslatef( 145, 0, 0);
          desenhaUrano();
	glPopMatrix();
    
 	glPushMatrix();
          glRotatef( anguloNetuno, 0, 1, 0); 
          glTranslatef( 160, 0, 0);
          desenhaNetuno();
	glPopMatrix();
	


    glutSwapBuffers();
//   glFlush();
    glEnable(GL_DEPTH_TEST);
}

void GerenciaMouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		// Salva os par?metros atuais
		x_ini = x;
		y_ini = y;
		rotX_ini = xrot;
		rotY_ini = yrot;
		bot = button;
	}
	else bot = -1;
}

/* velocidade dos planetas 

	[planeta]              [velocidade]

	Mercurio			    48.92 km/s		
	Venus					35.02 km/s
	Terra					29.78 km/s
	Marte					24.07 km/s
	Jupiter					13.05 km/s	
	Saturno					9.64  km/s
	Urano					6.81  km/s
	Netuno					5.43  km/s

*/
void
TimerFunction( int value ){

anguloMercurio += 4;
if( anguloMercurio >= 360 ) anguloMercurio = 0;

anguloVenus+= 3;
if( anguloVenus >= 360 ) anguloVenus = 0;

anguloTerra += 2;
if( anguloTerra >= 360 ) anguloTerra = 0;

anguloLua += 6;
if( anguloLua >= 360 ) anguloLua = 0;

anguloMarte += 1.70;
if( anguloMarte >= 360 ) anguloMarte = 0;

anguloJupiter += 1.60;
if( anguloJupiter >= 360 ) anguloJupiter = 0;

anguloSaturno += 1.50;
if( anguloSaturno >= 360 ) anguloSaturno = 0;

anguloUrano += 1.40;
if( anguloUrano >= 360 ) anguloUrano = 0;

anguloNetuno += 1.30;
if( anguloNetuno >= 360 ) anguloNetuno = 0;


glutPostRedisplay();
glutTimerFunc( 33, TimerFunction, 1);
}

// Fun??o callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	15.0
#define SENS_TRANSL	30.0
void GerenciaMovim(int x, int y)
{
	// Bot?o esquerdo ?
	if(bot==GLUT_LEFT_BUTTON)
	{
		// Calcula diferen?as
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica ?ngulos
		yrot = rotY_ini - deltax/SENS_ROT;
		xrot = rotX_ini - deltay/SENS_ROT;
	}
	glutPostRedisplay();
}
// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
//
//
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )  
{
	switch ( key ) 
				{
  		  case 27:        // When Escape Is Pressed...
  				    exit ( 0 );   // Exit The Program
  				    break;        // Ready For Next Case
  				    
		    
    default:        // Now Wrap It Up
      break;
  }
}

// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )  
//
//
// **********************************************************************
void arrow_keys ( int a_keys, int x, int y )  
{
	switch ( a_keys ) 
	{
		case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
			glutFullScreen ( ); // Go Into Full Screen Mode
			break;
	    case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
			glutInitWindowSize  ( 700, 500 ); 
			break;
		default:
			break;
	}
}

// **********************************************************************
//  void main ( int argc, char** argv )
//
//
// **********************************************************************
int main ( int argc, char** argv )   
{
	glutInit            ( &argc, argv ); 
	glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA ); 
	glutInitWindowPosition (0,0);
	glutInitWindowSize  ( 3000, 650 ); 
	glutCreateWindow    ( "Computa??o Gr?fica - Trabalho Planetario." ); 
		
	init ();
	initTexture ();
	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	
    glutTimerFunc(10,TimerFunction,0);		
	glutDisplayFunc ( display );  
	glutReshapeFunc ( reshape );
	// Registra a fun??o callback para eventos de bot?es do mouse	
	glutMouseFunc(GerenciaMouse);
	 
	// Registra a fun??o callback para eventos de movimento do mouse	
	glutMotionFunc(GerenciaMovim);

	glutKeyboardFunc ( keyboard );
	glutSpecialFunc ( arrow_keys );
//	glutIdleFunc ( display );
	glutMainLoop ( );          
}
