#include "types.h"
uint8_t step[] = {
    8, 8, 1, // X (SetDrawingF) x 1
    0, 0, 1, // HAT_UP x 1
    4, 8, 1, // A (SetTool) x 1
    0, 8, 1, // NONE x 1
    0, 4, 1, // HAT_DOWN x 1
    0, 8, 1, // NONE x 1
    4, 8, 1, // A (ResetPalette) x 1
    0, 8, 1, // NONE x 1
    0, 2, 1, // HAT_RIGHT x 1
    4, 8, 1, // A (SetTool) x 1
    0, 8, 1, // NONE x 1
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 12, // HAT_LEFT x 12
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 9, // HAT_LEFT x 9
    0, 4, 1, // HAT_DOWN x 1
    32, 8, 1, // R (ColorR1) x 1
    0, 8, 1, // NONE x 1
    0, 4, 2, // HAT_DOWN x 2
    0, 6, 14, // HAT_LEFT x 14
    0, 4, 1, // HAT_DOWN x 1
    32, 8, 1, // R (ColorR2) x 1
    0, 8, 1, // NONE x 1
    0, 6, 1, // HAT_LEFT x 1
    0, 4, 1, // HAT_DOWN x 1
    0, 2, 1, // HAT_RIGHT x 1
    0, 4, 2, // HAT_DOWN x 2
    32, 8, 1, // R (ColorR3) x 1
    0, 8, 1, // NONE x 1
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 12, // HAT_LEFT x 12
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 7, // HAT_LEFT x 7
    0, 4, 1, // HAT_DOWN x 1
    32, 8, 1, // R (ColorR4) x 1
    0, 8, 1, // NONE x 1
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 12, // HAT_LEFT x 12
    0, 4, 1, // HAT_DOWN x 1
    0, 2, 2, // HAT_RIGHT x 2
    0, 4, 1, // HAT_DOWN x 1
    32, 8, 1, // R (ColorR5) x 1
    0, 8, 1, // NONE x 1
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 11, // HAT_LEFT x 11
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 1, // HAT_LEFT x 1
    0, 4, 1, // HAT_DOWN x 1
    32, 8, 1, // R (ColorR6) x 1
    0, 8, 1, // NONE x 1
    0, 4, 2, // HAT_DOWN x 2
    0, 6, 5, // HAT_LEFT x 5
    0, 4, 1, // HAT_DOWN x 1
    32, 8, 1, // R (ColorR7) x 1
    0, 8, 1, // NONE x 1
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 11, // HAT_LEFT x 11
    0, 4, 2, // HAT_DOWN x 2
    32, 8, 1, // R (ColorR8) x 1
    0, 8, 1, // NONE x 1
    0, 2, 7, // HAT_RIGHT x 7
    0, 4, 1, // HAT_DOWN x 1
    0, 2, 2, // HAT_RIGHT x 2
    0, 4, 1, // HAT_DOWN x 1
    0, 6, 1, // HAT_LEFT x 1
    0, 4, 1, // HAT_DOWN x 1
    4, 8, 1, // A x 1
    8, 8, 1, // X (SetDrawingF) x 1
    0, 6, 1, // HAT_LEFT x 1
    0, 4, 1, // HAT_DOWN x 1
    4, 8, 1, // A (SetTool) x 1
    0, 8, 2, // NONE x 2
    16, 8, 6, // L (ColorL2) x 6
    8, 8, 1, // X (SetDrawingF) x 1
    0, 4, 4, // HAT_DOWN x 4
    4, 8, 2, // A (SetTool) x 2
    8, 8, 1, // X (SetDrawingF) x 1
    0, 0, 4, // HAT_UP x 4
    4, 8, 1, // A (SetTool) x 1
    16, 8, 2, // L (ColorL0) x 2
    4, 8, 1, // A x 1
    32, 6, 1, // HAT_LEFT+R (ColorR4) x 1
    32, 8, 3, // NONE+R (ColorR4) x 3
    4, 8, 1, // A x 1
    4, 0, 1, // HAT_UP+A x 1
    16, 2, 1, // HAT_RIGHT+L (ColorL3) x 1
    4, 8, 1, // A x 1
    16, 2, 1, // HAT_RIGHT+L (ColorL1) x 1
    16, 8, 1, // NONE+L (ColorL1) x 1
    4, 8, 1, // A x 1
    4, 4, 2, // HAT_DOWN+A x 2
    32, 6, 1, // HAT_LEFT+R (ColorR3) x 1
    32, 8, 1, // NONE+R (ColorR3) x 1
    4, 8, 1, // A x 1
    32, 6, 1, // HAT_LEFT+R (ColorR5) x 1
    32, 8, 1, // NONE+R (ColorR5) x 1
    4, 8, 1, // A x 1
    4, 6, 1, // HAT_LEFT+A x 1
    32, 0, 1, // HAT_UP+R (ColorR7) x 1
    32, 8, 1, // NONE+R (ColorR7) x 1
    4, 8, 1, // A x 1
    16, 0, 1, // HAT_UP+L (ColorL4) x 1
    16, 8, 2, // NONE+L (ColorL4) x 2
    4, 8, 1, // A x 1
    4, 0, 1, // HAT_UP+A x 1
    4, 2, 1, // HAT_RIGHT+A x 1
    16, 2, 1, // HAT_RIGHT+L (ColorL3) x 1
    4, 8, 1, // A x 1
    16, 2, 1, // HAT_RIGHT+L (ColorL0) x 1
    16, 8, 2, // NONE+L (ColorL0) x 2
    4, 8, 1, // A x 1
    4, 2, 1, // HAT_RIGHT+A x 1
    4, 4, 4, // HAT_DOWN+A x 4
    32, 6, 1, // HAT_LEFT+R (ColorR1) x 1
    4, 8, 1, // A x 1
    32, 6, 1, // HAT_LEFT+R (ColorR3) x 1
    32, 8, 1, // NONE+R (ColorR3) x 1
    4, 8, 1, // A x 1
    32, 6, 1, // HAT_LEFT+R (ColorR4) x 1
    4, 8, 1, // A x 1
    4, 6, 2, // HAT_LEFT+A x 2
    4, 0, 1, // HAT_UP+A x 1
    32, 0, 1, // HAT_UP+R (ColorR7) x 1
    32, 8, 2, // NONE+R (ColorR7) x 2
    4, 8, 1, // A x 1
    16, 0, 1, // HAT_UP+L (ColorL4) x 1
    16, 8, 2, // NONE+L (ColorL4) x 2
    4, 8, 1, // A x 1
    4, 0, 2, // HAT_UP+A x 2
    4, 2, 1, // HAT_RIGHT+A x 1
    16, 2, 1, // HAT_RIGHT+L (ColorL3) x 1
    4, 8, 1, // A x 1
    4, 2, 3, // HAT_RIGHT+A x 3
    16, 2, 1, // HAT_RIGHT+L (ColorL1) x 1
    16, 8, 1, // NONE+L (ColorL1) x 1
    4, 8, 1, // A x 1
    4, 4, 6, // HAT_DOWN+A x 6
    16, 6, 1, // HAT_LEFT+L (ColorL0) x 1
    4, 8, 1, // A x 1
    4, 6, 2, // HAT_LEFT+A x 2
    32, 6, 1, // HAT_LEFT+R (ColorR4) x 1
    32, 8, 3, // NONE+R (ColorR4) x 3
    4, 8, 1, // A x 1
    4, 6, 3, // HAT_LEFT+A x 3
    4, 0, 2, // HAT_UP+A x 2
    16, 0, 1, // HAT_UP+L (ColorL3) x 1
    4, 8, 1, // A x 1
    32, 0, 1, // HAT_UP+R (ColorR4) x 1
    4, 8, 1, // A x 1
    4, 0, 1, // HAT_UP+A x 1
    16, 0, 1, // HAT_UP+L (ColorL0) x 1
    16, 8, 3, // NONE+L (ColorL0) x 3
    4, 8, 1, // A x 1
    32, 0, 1, // HAT_UP+R (ColorR4) x 1
    32, 8, 3, // NONE+R (ColorR4) x 3
    4, 8, 1, // A x 1
    4, 2, 1, // HAT_RIGHT+A x 1
    16, 2, 1, // HAT_RIGHT+L (ColorL0) x 1
    16, 8, 3, // NONE+L (ColorL0) x 3
    4, 8, 1, // A x 1
    32, 2, 1, // HAT_RIGHT+R (ColorR3) x 1
    32, 8, 2, // NONE+R (ColorR3) x 2
    4, 8, 1, // A x 1
    4, 2, 4, // HAT_RIGHT+A x 4
    16, 2, 1, // HAT_RIGHT+L (ColorL1) x 1
    16, 8, 1, // NONE+L (ColorL1) x 1
    4, 8, 1, // A x 1
    4, 4, 4, // HAT_DOWN+A x 4
    16, 4, 1, // HAT_DOWN+L (ColorL0) x 1
    4, 8, 1, // A x 1
    32, 4, 1, // HAT_DOWN+R (ColorR1) x 1
    4, 8, 1, // A x 1
    4, 4, 2, // HAT_DOWN+A x 2
    4, 6, 2, // HAT_LEFT+A x 2
    16, 6, 1, // HAT_LEFT+L (ColorL0) x 1
    4, 8, 1, // A x 1
    32, 6, 1, // HAT_LEFT+R (ColorR1) x 1
    4, 8, 1, // A x 1
    16, 6, 1, // HAT_LEFT+L (ColorL0) x 1
    4, 8, 1, // A x 1
    32, 6, 1, // HAT_LEFT+R (ColorR4) x 1
    32, 8, 3, // NONE+R (ColorR4) x 3
    4, 8, 1, // A x 1
    4, 6, 3, // HAT_LEFT+A x 3
    16, 0, 1, // HAT_UP+L (ColorL3) x 1
    4, 8, 1, // A x 1
    32, 0, 1, // HAT_UP+R (ColorR4) x 1
    4, 8, 1, // A x 1
    4, 0, 7, // HAT_UP+A x 7
    4, 2, 3, // HAT_RIGHT+A x 3
    16, 2, 1, // HAT_RIGHT+L (ColorL3) x 1
    4, 8, 1, // A x 1
    4, 2, 4, // HAT_RIGHT+A x 4
    16, 2, 1, // HAT_RIGHT+L (ColorL1) x 1
    16, 8, 1, // NONE+L (ColorL1) x 1
    4, 8, 1, // A x 1
    4, 2, 1, // HAT_RIGHT+A x 1
    4, 4, 5, // HAT_DOWN+A x 5
    0, 4, 4, // HAT_DOWN x 4
    4, 4, 2, // HAT_DOWN+A x 2
    4, 6, 2, // HAT_LEFT+A x 2
    4, 0, 1, // HAT_UP+A x 1
    0, 0, 10, // HAT_UP x 10
    4, 0, 1, // HAT_UP+A x 1
    4, 2, 2, // HAT_RIGHT+A x 2
    32, 2, 1, // HAT_RIGHT+R (ColorR6) x 1
    32, 8, 4, // NONE+R (ColorR6) x 4
    4, 8, 1, // A x 1
    4, 2, 1, // HAT_RIGHT+A x 1
    32, 2, 1, // HAT_RIGHT+R (ColorR8) x 1
    32, 8, 1, // NONE+R (ColorR8) x 1
    4, 8, 1, // A x 1
    4, 2, 3, // HAT_RIGHT+A x 3
    16, 2, 1, // HAT_RIGHT+L (ColorL6) x 1
    16, 8, 1, // NONE+L (ColorL6) x 1
    4, 8, 1, // A x 1
    4, 2, 3, // HAT_RIGHT+A x 3
    16, 5, 6, // HAT_DOWN_LEFT+L (ColorL0) x 6
    0, 6, 9, // HAT_LEFT x 9
 0 };
static int numsteps = 219;
