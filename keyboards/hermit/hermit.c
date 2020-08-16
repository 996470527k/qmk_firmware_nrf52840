#include "hermit.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
 /* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */

   { 0, B_8,   A_8,   C_8  },
   { 0, B_6,   A_6,   C_6  },
   { 0, B_7,   A_7,   C_7  },
   { 0, B_9,   A_9,   C_9  },
   { 0, B_10,  A_10,  C_10 },
   { 0, B_11,  A_11,  C_11 },
   { 0, B_12,  A_12,  C_12 },
   { 1, B_6,   A_6,   C_6  },
   { 1, B_7,   A_7,   C_7  },
   { 1, B_8,   A_8,   C_8  },
   { 1, B_9,   A_9,   C_9  },
   { 1, B_10,  A_10,  C_10 },
   { 1, B_12,  A_12,  C_12 },
   { 1, B_11,  A_11,  C_11 },

   { 0, B_4,   A_4,   C_4  },
   { 0, E_4,   D_4,   F_4  },
   { 0, E_8,   D_8,   F_8  },
   { 0, E_6,   D_6,   F_6  },
   { 0, E_7,   D_7,   F_7  },
   { 0, E_9,   D_9,   F_9  },
   { 0, E_10,  D_10,  F_10 },
   { 0, E_11,  D_11,  F_11 },
   { 0, E_12,  D_12,  F_12 },
   { 1, B_4,   A_4,   C_4  },
   { 1, E_4,   D_4,   F_4  },
   { 1, E_6,   D_6,   F_6  },
   { 1, E_7,   D_7,   F_7  },
   { 1, E_8,   D_8,   F_8  },
   { 1, E_9,   D_9,   F_9  },

   { 0, B_5,   A_5,   C_5  },
   { 0, E_5,   D_5,   F_5  },
   { 0, H_3,   G_3,   I_3  },
   { 0, H_5,   G_5,   I_5  },
   { 0, H_4,   G_4,   I_4  },
   { 0, H_8,   G_8,   I_8  },
   { 0, H_6,   G_6,   I_6  },
   { 0, H_7,   G_7,   I_7  },
   { 0, H_9,   G_9,   I_9  },
   { 1, B_5,   A_5,   C_5  },
   { 1, E_5,   D_5,   F_5  },
   { 1, H_5,   G_5,   I_5  },
   { 1, H_4,   G_4,   I_4  },
   { 1, H_6,   G_6,   I_6  },
   { 1, H_7,   G_7,   I_7  },

   { 0, E_3,   D_3,   F_3  },
   { 0, H_1,   G_1,   I_1  },
   { 0, K_2,   J_2,   L_2  },
   { 0, K_3,   J_3,   L_3  },
   { 0, K_4,   J_4,   L_4  },
   { 0, K_6,   J_6,   L_6  },
   { 0, K_9,   J_9,   L_9  },
   { 0, H_10,  G_10,  I_10 },
   { 1, B_2,   A_2,   C_2  },
   { 1, E_2,   D_2,   F_2  },
   { 1, H_2,   G_2,   I_2  },
   { 1, H_3,   G_3,   I_3  },
   { 1, K_4,   J_4,   L_4  },
   { 1, K_5,   J_5,   L_5  },

   { 0, B_3,   A_3,   C_3  },
   { 0, E_1,   D_1,   F_1  },
   { 0, H_2,   G_2,   I_2  },
   { 0, K_1,   J_1,   L_1  },
   { 0, K_5,   J_5,   L_5  },
   { 0, K_8,   J_8,   L_8  },
   { 0, K_7,   J_7,   L_7  },
   { 0, K_10,  J_10,  L_10 },
   { 0, H_11,  G_11,  I_11 },
   { 1, B_3,   A_3,   C_3  },
   { 1, E_3,   D_3,   F_3  },
   { 1, H_1,   G_1,   I_1  },
   { 1, K_10,  J_10,  L_10 },
   { 1, K_2,   J_2,   L_2  },
   { 1, K_6,   J_6,   L_6  },

   { 0, B_1,   A_1,   C_1  },
   { 0, B_2,   A_2,   C_2  },
   { 0, E_2,   D_2,   F_2  },
   { 0, H_12,  G_12,  I_12  },
   { 1, B_1,   A_1,   C_1  },
   { 1, E_1,   D_1,   F_1  },
   { 1, K_1,   J_1,   L_1  },
   { 1, K_3,   J_3,   L_3  },
   { 1, K_12,  J_12,  L_12 },
   { 1, K_9,   J_9,   L_9  },
   { 1, K_11,  J_11,  L_11 },
   { 1, K_8,   J_8,   L_8  },
   { 1, K_7,   J_7,   L_7  },
   { 1, H_10,  G_10,  I_10 },

   { 0, K_11,  J_11,  L_11 },
   { 0, K_12,  J_12,  L_12 },
   { 1, E_10,  D_10,  F_10 },
   { 1, E_12,  D_12,  F_12 },
   { 1, E_11,  D_11,  F_11 },
   { 1, H_12,  G_12,  I_12 },
   { 1, H_11,  G_11,  I_11 },
   { 1, H_8,   G_8,   I_8  },
   { 1, H_9,   G_9,   I_9  },
};

led_config_t g_led_config = {{
    {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 98},
    {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28},
    {29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43},
    {96, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57},
    {58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72},
    {73, 74, 75, 102,76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86},
    {87, 88, 101,100,99, 97, 89, 90, 91, 92, 93, 94, 95},
}, {
    { 5.7352   , 5.1402  } , { 27.533   , 5.1402  } , { 38.4319  , 5.1402  } , { 49.3308  , 5.1402  } , { 60.2288  , 5.1402  } , { 76.5779  , 5.1402  } , { 87.4768  , 5.1402  } , { 98.3757  , 5.1402  } , { 109.2745 , 5.1402  } , { 125.6228 , 5.1402  } , { 136.5217 , 5.1402  } , { 147.4206 , 5.1402  } , { 158.3194 , 5.1402  } , { 171.9422 , 5.1402 } , { 5.7352   , 17.3484 },
    { 16.6341  , 17.3484 } , { 27.533   , 17.3484 } , { 38.4319  , 17.3484 } , { 49.3308  , 17.3484 } , { 60.2288  , 17.3484 } , { 71.1279  , 17.3484 } , { 82.0274  , 17.3484 } , { 92.9262  , 17.3484 } , { 103.8251 , 17.3484 } , { 114.724  , 17.3484 } , { 125.6228 , 17.3484 } , { 136.5217 , 17.3484 } , { 152.87   , 17.3484 } , { 171.9422 , 17.3484 } , { 8.4591  , 27.1157 },
    { 22.0835  , 27.1157 } , { 32.9825  , 27.1157 } , { 43.8813  , 27.1157 } , { 54.7802  , 27.1157 } , { 65.6791  , 27.1157 } , { 76.5779  , 27.1157 } , { 87.4768  , 27.1157 } , { 98.3757  , 27.1157 } , { 109.2745 , 27.1157 } , { 120.1734 , 27.1157 } , { 131.0723 , 27.1157 } , { 141.9711 , 27.1157 } , { 155.5939 , 27.1157 } , { 171.9422 , 27.1157 } , { 24.8075 , 36.8829 },
    { 35.7064  , 36.8829 } , { 46.6052  , 36.8829 } , { 57.5041  , 36.8829 } , { 68.4029  , 36.8829 } , { 79.3018  , 36.8829 } , { 90.2007  , 36.8829 } , { 101.0995 , 36.8829 } , { 111.9984 , 36.8829 } , { 122.8973 , 36.8829 } , { 133.7961 , 36.8829 } , { 151.5066 , 36.8829 } , { 185.5666 , 36.8829 } , { 196.4655 , 36.8829 } , { 12.547   , 46.6502 } , { 30.2569 , 46.6502 },
    { 41.1558  , 46.6502 } , { 52.0547  , 46.6502 } , { 62.9535  , 46.6502 } , { 73.8524  , 46.6502 } , { 84.7512  , 46.6502 } , { 95.6501  , 46.6502 } , { 106.549  , 46.6502 } , { 117.4478 , 46.6502 } , { 128.3467 , 49.0927 } , { 148.7822 , 46.6502 } , { 171.9422 , 46.6502 } , { 185.5666 , 46.6502 } , { 196.4655 , 46.6502 } , { 7.0976   , 56.4174 } , { 20.7203 , 56.4174 },
    { 34.3448  , 56.4174 } , { 116.0862 , 56.4174 } , { 129.7089 , 56.4174 } , { 143.3334 , 56.4174 } , { 161.0433 , 58.8599 } , { 171.9422 , 58.8599 } , { 182.841  , 58.8599 } , { 196.4655 , 56.4174 } , { 207.3638 , 56.4174 } , { 207.3638 , 46.6502 } , { 207.3638 , 36.8829 } , { 207.3638 , 27.1157 } , { 61.8778  , 56.4174 } , { 88.5524 , 56.4174 } , { 196.4655 , 17.3484 },
    { 207.3638 , 17.3484 } , { 218.2626 , 17.3484 } , { 218.2626 , 31.9993 } , { 218.2626 , 51.5338 } , { 185.5666 , 27.1157 } , { 196.4655 , 27.1157 } ,

    // Underglow LEDs
   // { 9.8215   , 36.8829 } , { 185.5666 , 17.3484 } , { 185.5666 , 5.1402  } , { 196.4655 , 5.1402  } , { 207.3638 , 5.1402  } , { 218.2626 , 5.1402  } , { 75.214   , 56.4174 } ,
}, {
    1 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 1 ,
    1 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 1 ,
    1 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 1 ,
    1 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 1 ,
    1 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 1 ,
    1 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 1 ,
        1 , 1 , 1 , 1 , 1 , 1 ,

       // Underglow LEDs
     //1 , 1 , 1 , 1 , 1 , 1 , 1
}};
#endif
