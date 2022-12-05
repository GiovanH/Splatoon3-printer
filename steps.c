#include "types.h"
uint8_t step[] = {
    0b10001000, 1, // b=8 1000 h=8 1000 LCLICK x 1
    0b00000011, 9, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 9
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (170, 69))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (170, 73))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (170, 77))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (170, 81))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (170, 85))+A x 1
    0b00000001, 6, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 6
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (177, 79))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (180, 76))+A x 1
    0b00000100, 5, // b=0 0000 h=4 0100 HAT_DOWN x 5
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (180, 82))+A x 1
    0b00000011, 6, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 6
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (190, 88))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (192, 85))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (192, 81))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (192, 77))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (192, 73))+A x 1
    0b00000010, 11, // b=0 0000 h=2 0010 HAT_RIGHT x 11
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (204, 73))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (205, 77))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (205, 81))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (205, 85))+A x 1
    0b00000001, 6, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 6
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (213, 79))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (215, 82))+A x 1
    0b00000000, 7, // b=0 0000 h=0 0000 HAT_UP x 7
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (215, 74))+A x 1
    0b00000111, 5, // b=0 0000 h=7 0111 HAT_UP_LEFT x 5
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (207, 69))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 18, // b=0 0000 h=0 0000 HAT_UP x 18
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (208, 49))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (205, 45))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (206, 41))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (206, 37))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (206, 33))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 7, // b=0 0000 h=2 0010 HAT_RIGHT x 7
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (215, 32))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00000010, 7, // b=0 0000 h=2 0010 HAT_RIGHT x 7
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (225, 30))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (226, 34))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (226, 38))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (226, 42))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (226, 46))+A x 1
    0b00000001, 6, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 6
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (233, 39))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (236, 36))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (236, 32))+A x 1
    0b00000100, 8, // b=0 0000 h=4 0100 HAT_DOWN x 8
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (236, 41))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (236, 45))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (245, 36))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (246, 40))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (246, 44))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (246, 48))+A x 1
    0b00000001, 7, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 7
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (254, 41))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (256, 44))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (256, 48))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (265, 39))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (268, 36))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (266, 33))+A x 1
    0b00000011, 5, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 5
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (272, 38))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (275, 35))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (276, 39))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (276, 43))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (276, 47))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (285, 38))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (286, 42))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (286, 46))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 7, // b=0 0000 h=2 0010 HAT_RIGHT x 7
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (295, 45))+A x 1
    0b00000001, 9, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 9
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (305, 35))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (306, 39))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (306, 43))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (306, 47))+A x 1
    0b00000111, 10, // b=0 0000 h=7 0111 HAT_UP_LEFT x 10
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (296, 34))+A x 1
    0b00000111, 5, // b=0 0000 h=7 0111 HAT_UP_LEFT x 5
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (288, 29))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (285, 33))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00000110, 4, // b=0 0000 h=6 0110 HAT_LEFT x 4
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (277, 30))+A x 1
    0b00000101, 11, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 11
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (266, 43))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (266, 47))+A x 1
    0b00000111, 9, // b=0 0000 h=7 0111 HAT_UP_LEFT x 9
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (256, 37))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (256, 33))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (248, 29))+A x 1
    0b00000101, 16, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 16
    0b00000110, 14, // b=0 0000 h=6 0110 HAT_LEFT x 14
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (217, 45))+A x 1
    0b00000011, 24, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 24
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (242, 69))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (239, 73))+A x 1
    0b00000011, 5, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 5
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (245, 79))+A x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (250, 74))+A x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b00000010, 4, // b=0 0000 h=2 0010 HAT_RIGHT x 4
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (259, 70))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (260, 74))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (260, 78))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (260, 82))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (260, 86))+A x 1
    0b00000001, 6, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 6
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (267, 79))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (270, 76))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (270, 72))+A x 1
    0b00000100, 8, // b=0 0000 h=4 0100 HAT_DOWN x 8
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (270, 81))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (270, 85))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (279, 76))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (280, 80))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (280, 84))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (282, 88))+A x 1
    0b00000001, 6, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 6
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (289, 81))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (290, 85))+A x 1
    0b00000000, 7, // b=0 0000 h=0 0000 HAT_UP x 7
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (290, 77))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (290, 73))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (282, 69))+A x 1
    0b00000010, 20, // b=0 0000 h=2 0010 HAT_RIGHT x 20
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (303, 69))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (305, 72))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (305, 76))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (305, 80))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (305, 84))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (305, 88))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00000110, 50, // b=0 0000 h=6 0110 HAT_LEFT x 50
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (251, 85))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00000110, 5, // b=0 0000 h=6 0110 HAT_LEFT x 5
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (242, 88))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (240, 85))+A x 1
    0b00000111, 52, // b=0 0000 h=7 0111 HAT_UP_LEFT x 52
    0b00000110, 5, // b=0 0000 h=6 0110 HAT_LEFT x 5
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (182, 33))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (178, 39))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (181, 42))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (181, 46))+A x 1
    0b00000111, 7, // b=0 0000 h=7 0111 HAT_UP_LEFT x 7
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (173, 38))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (171, 41))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (171, 45))+A x 1
    0b00000111, 8, // b=0 0000 h=7 0111 HAT_UP_LEFT x 8
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (162, 36))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (160, 40))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (161, 44))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (153, 48))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (151, 45))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (151, 41))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (151, 37))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (151, 33))+A x 1
    0b00000101, 8, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 8
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (142, 42))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (140, 38))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (141, 34))+A x 1
    0b00000111, 5, // b=0 0000 h=7 0111 HAT_UP_LEFT x 5
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (133, 29))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (130, 33))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (131, 37))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (131, 41))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (131, 45))+A x 1
    0b00000111, 9, // b=0 0000 h=7 0111 HAT_UP_LEFT x 9
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (121, 35))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (117, 39))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (115, 43))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (116, 47))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000000, 4, // b=0 0000 h=0 0000 HAT_UP x 4
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (112, 38))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (110, 34))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (111, 30))+A x 1
    0b00000010, 8, // b=0 0000 h=2 0010 HAT_RIGHT x 8
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (120, 30))+A x 1
    0b00000011, 16, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 16
    0b00000010, 4, // b=0 0000 h=2 0010 HAT_RIGHT x 4
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (141, 46))+A x 1
    0b00000001, 16, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 16
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (160, 30))+A x 1
    0b00000010, 9, // b=0 0000 h=2 0010 HAT_RIGHT x 9
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (170, 30))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (171, 34))+A x 1
    0b00000101, 34, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 34
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (137, 69))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (134, 73))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (135, 77))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (135, 81))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (135, 85))+A x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (143, 81))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (145, 84))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (145, 88))+A x 1
    0b00000000, 9, // b=0 0000 h=0 0000 HAT_UP x 9
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (145, 78))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (145, 74))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000110, 29, // b=0 0000 h=6 0110 HAT_LEFT x 29
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (111, 70))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (110, 74))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (106, 78))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (102, 79))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (100, 82))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (100, 86))+A x 1
    0b00000111, 8, // b=0 0000 h=7 0111 HAT_UP_LEFT x 8
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (91, 77))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (89, 81))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (86, 78))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (83, 75))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (80, 78))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (80, 82))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (80, 86))+A x 1
    0b00000010, 8, // b=0 0000 h=2 0010 HAT_RIGHT x 8
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (89, 86))+A x 1
    0b00000001, 10, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 10
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (100, 75))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (100, 71))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000110, 7, // b=0 0000 h=6 0110 HAT_LEFT x 7
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (91, 70))+A x 1
    0b00000110, 9, // b=0 0000 h=6 0110 HAT_LEFT x 9
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (81, 70))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000110, 10, // b=0 0000 h=6 0110 HAT_LEFT x 10
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (69, 69))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (67, 72))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (67, 76))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (67, 80))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (67, 84))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (65, 88))+A x 1
    0b00000111, 15, // b=0 0000 h=7 0111 HAT_UP_LEFT x 15
    0b00000110, 8, // b=0 0000 h=6 0110 HAT_LEFT x 8
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (41, 73))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (39, 77))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (40, 81))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (40, 85))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00000110, 4, // b=0 0000 h=6 0110 HAT_LEFT x 4
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (32, 88))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (30, 85))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (30, 81))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (30, 77))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (30, 73))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000110, 8, // b=0 0000 h=6 0110 HAT_LEFT x 8
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (17, 69))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (15, 72))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (15, 76))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (15, 80))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (15, 84))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (15, 88))+A x 1
    0b00000111, 12, // b=0 0000 h=7 0111 HAT_UP_LEFT x 12
    0b00000000, 26, // b=0 0000 h=0 0000 HAT_UP x 26
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (3, 49))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (3, 45))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (3, 41))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (3, 37))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (3, 33))+A x 1
    0b00000011, 4, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 4
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (9, 37))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (12, 34))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (13, 38))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (13, 42))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (13, 46))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (22, 37))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (23, 41))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (23, 45))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (32, 36))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (33, 40))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (33, 44))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (42, 35))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (43, 39))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (43, 43))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (45, 47))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000010, 5, // b=0 0000 h=2 0010 HAT_RIGHT x 5
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (52, 48))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (54, 44))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (55, 40))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (55, 36))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (55, 32))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00000010, 7, // b=0 0000 h=2 0010 HAT_RIGHT x 7
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (65, 30))+A x 1
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b00000010, 6, // b=0 0000 h=2 0010 HAT_RIGHT x 6
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (75, 33))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (78, 29))+A x 1
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (85, 32))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (81, 39))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (76, 44))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (78, 48))+A x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (85, 44))+A x 1
    0b00000011, 24, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 24
    0b00000100, 15, // b=0 0000 h=4 0100 HAT_DOWN x 15
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (109, 84))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (110, 88))+A x 1
    0b00000111, 58, // b=0 0000 h=7 0111 HAT_UP_LEFT x 58
    0b00000110, 7, // b=0 0000 h=6 0110 HAT_LEFT x 7
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (44, 30))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000110, 8, // b=0 0000 h=6 0110 HAT_LEFT x 8
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (33, 32))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00000110, 4, // b=0 0000 h=6 0110 HAT_LEFT x 4
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (25, 29))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (23, 33))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00000110, 5, // b=0 0000 h=6 0110 HAT_LEFT x 5
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (14, 30))+A x 1
    0b00000010, 255, // b=0 0000 h=2 0010 HAT_RIGHT x 255
    0b00000010, 35, // b=0 0000 h=2 0010 HAT_RIGHT x 35
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (305, 30))+A x 1
    0b01100001, 1, // b=6 0110 h=1 0001 HAT_UP_RIGHT+L x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (307, 28))+A x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (308, 28))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (308, 29))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (309, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (310, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (311, 28))+A x 1
    0b01000101, 4, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (310, 29))+A x 4
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (308, 32))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (307, 33))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (308, 33))+A x 1
    0b01000100, 4, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (308, 34))+A x 4
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (309, 38))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (310, 38))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (309, 39))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (310, 39))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (311, 38))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (312, 38))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (311, 39))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (311, 40))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (312, 39))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (314, 38))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (313, 39))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (313, 40))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (314, 39))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (315, 39))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (314, 40))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (315, 40))+A x 1
    0b00000110, 5, // b=0 0000 h=6 0110 HAT_LEFT x 5
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (309, 40))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (308, 41))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (304, 45))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (308, 45))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (309, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (308, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (308, 50))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (309, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (311, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (310, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (310, 50))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (311, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (313, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (312, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (312, 50))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (313, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (315, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (314, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (314, 50))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (315, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (317, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (316, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (316, 50))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (317, 49))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (318, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (317, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (318, 50))+A x 1
    0b00000110, 11, // b=0 0000 h=6 0110 HAT_LEFT x 11
    0b01000110, 2, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (306, 50))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (304, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (304, 50))+A x 1
    0b00000111, 5, // b=0 0000 h=7 0111 HAT_UP_LEFT x 5
    0b01000111, 2, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (298, 44))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (298, 43))+A x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (298, 45))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (297, 47))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (298, 47))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (295, 50))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (294, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (295, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (295, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (294, 50))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (293, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (294, 48))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (293, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (292, 49))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (290, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (291, 48))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (292, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (291, 49))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (289, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (290, 48))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (289, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (288, 49))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (286, 49))+A x 1
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (285, 48))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (287, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (288, 48))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (286, 50))+A x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (288, 50))+A x 2
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (292, 50))+A x 2
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (293, 46))+B x 3
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (288, 39))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (288, 40))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 2, // b=4 0100 h=0 0000 HAT_UP (Moveto (288, 38))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (287, 36))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (288, 35))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (288, 36))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (287, 35))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (288, 34))+A x 1
    0b01000000, 2, // b=4 0100 h=0 0000 HAT_UP (Moveto (288, 33))+A x 2
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (289, 31))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (291, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (293, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (292, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (292, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (293, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (295, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (294, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (294, 30))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (295, 29))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (295, 30))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (294, 31))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (295, 31))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (294, 32))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (296, 31))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (298, 32))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (295, 36))+B x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (296, 36))+B x 2
    0b00000001, 5, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 5
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (303, 30))+B x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (303, 31))+B x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (303, 29))+B x 1
    0b00000100, 4, // b=0 0000 h=4 0100 HAT_DOWN x 4
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (303, 34))+B x 3
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (304, 41))+A x 1
    0b00000001, 10, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 10
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (315, 30))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (318, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (317, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (315, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (316, 28))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (315, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (314, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (312, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (313, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (314, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (313, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (311, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (312, 28))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (310, 30))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (311, 30))+A x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (314, 30))+A x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (317, 30))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (318, 29))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (318, 30))+A x 1
    0b00000110, 9, // b=0 0000 h=6 0110 HAT_LEFT x 9
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (308, 30))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000110, 14, // b=0 0000 h=6 0110 HAT_LEFT x 14
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (291, 28))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (289, 27))+B x 3
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (283, 32))+B x 3
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (283, 37))+B x 3
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b01000111, 2, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (278, 34))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (278, 33))+A x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 3, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (278, 35))+A x 3
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (274, 41))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (270, 38))+B x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (270, 39))+B x 1
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (269, 38))+B x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (268, 39))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (268, 40))+A x 2
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (264, 45))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (268, 45))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (264, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (264, 50))+A x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (265, 50))+A x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (268, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (268, 50))+A x 1
    0b00000001, 5, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 5
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (274, 45))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (278, 41))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (278, 45))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (274, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (274, 50))+A x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (275, 50))+A x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (278, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (278, 50))+A x 1
    0b00000001, 5, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 5
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (284, 44))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (288, 44))+A x 1
    0b00000111, 12, // b=0 0000 h=7 0111 HAT_UP_LEFT x 12
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (275, 32))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (274, 31))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (274, 32))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (273, 34))+B x 2
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (270, 33))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (270, 34))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (269, 33))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (268, 31))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (267, 30))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (268, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (267, 28))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (266, 29))+A x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (264, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (265, 29))+A x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (265, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (264, 29))+A x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (264, 28))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (266, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (267, 29))+A x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (268, 30))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (264, 35))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (265, 36))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (263, 38))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (263, 39))+B x 2
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (258, 35))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (254, 31))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (255, 30))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (254, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (255, 28))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (255, 29))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (254, 30))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (253, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (254, 28))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (253, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (252, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (252, 30))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (251, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (252, 28))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (251, 28))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (249, 27))+B x 3
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (244, 31))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (245, 31))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (244, 32))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (245, 32))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (246, 31))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (246, 32))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (245, 33))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (246, 33))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (247, 32))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (248, 32))+A x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (249, 31))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (247, 33))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (248, 33))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (247, 34))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (248, 34))+A x 1
    0b01000100, 4, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (248, 35))+A x 4
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (249, 41))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 42))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (249, 42))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (250, 41))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (251, 41))+A x 1
    0b00100001, 2, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (252, 40))+B x 2
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (253, 40))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (251, 42))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (250, 42))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (253, 43))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (254, 46))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (258, 42))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (257, 41))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (258, 40))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (258, 41))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (257, 40))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (258, 39))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (254, 35))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (258, 31))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (253, 30))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00000110, 5, // b=0 0000 h=6 0110 HAT_LEFT x 5
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (244, 33))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (243, 35))+B x 3
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (238, 34))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (234, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (235, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (237, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (236, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (235, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (234, 29))+A x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (234, 28))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (237, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (238, 28))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (238, 29))+A x 2
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (234, 34))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (232, 37))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (233, 37))+B x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (230, 40))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (229, 39))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (230, 38))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (230, 39))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (229, 40))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (228, 40))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (229, 38))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (228, 36))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (224, 40))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (224, 44))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (228, 44))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (224, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (224, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (225, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (224, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (225, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (226, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (227, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (228, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (228, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (227, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (228, 50))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (226, 50))+A x 1
    0b00000111, 6, // b=0 0000 h=7 0111 HAT_UP_LEFT x 6
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (219, 44))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (219, 45))+B x 2
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (215, 50))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (214, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (215, 48))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (214, 47))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (213, 48))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (212, 50))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (213, 49))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (214, 46))+A x 1
    0b01000000, 2, // b=4 0100 h=0 0000 HAT_UP (Moveto (214, 45))+A x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (215, 43))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (214, 43))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (211, 48))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (212, 48))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (211, 49))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (209, 51))+B x 1
    0b00100110, 2, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (208, 51))+B x 2
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (209, 47))+B x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (208, 46))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (208, 45))+A x 3
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (204, 39))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (208, 35))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (204, 31))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (206, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (208, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (207, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (207, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (208, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (210, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (209, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (209, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (210, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (212, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (211, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (211, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (212, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (214, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (213, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (213, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (214, 29))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (215, 29))+A x 1
    0b00100011, 1, // b=2 0010 h=3 0011 HAT_DOWN_RIGHT (Moveto (216, 30))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (218, 31))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (218, 32))+A x 2
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (217, 34))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (217, 35))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (218, 34))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (218, 35))+A x 1
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 2, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (215, 35))+A x 2
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (213, 33))+B x 3
    0b00000110, 4, // b=0 0000 h=6 0110 HAT_LEFT x 4
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (208, 31))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (206, 28))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 4, // b=0 0000 h=4 0100 HAT_DOWN x 4
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (204, 35))+A x 1
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (208, 39))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (203, 44))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (203, 45))+B x 2
    0b00000011, 4, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 4
    0b00000010, 5, // b=0 0000 h=2 0010 HAT_RIGHT x 5
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (213, 50))+A x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (215, 49))+A x 1
    0b00000001, 9, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 9
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (224, 36))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (228, 32))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (228, 31))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (227, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (228, 28))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (223, 29))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (223, 30))+B x 2
    0b00000011, 9, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 9
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (232, 41))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (233, 41))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (234, 43))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (238, 39))+A x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (238, 38))+A x 1
    0b00000100, 4, // b=0 0000 h=4 0100 HAT_DOWN x 4
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (238, 43))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (234, 47))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (234, 48))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (235, 48))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (234, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (235, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (236, 48))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (237, 48))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (238, 47))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (238, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (237, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (237, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (238, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (238, 50))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (236, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (235, 50))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (234, 50))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (244, 42))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (244, 46))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (248, 46))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (244, 50))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (248, 50))+A x 1
    0b00000010, 5, // b=0 0000 h=2 0010 HAT_RIGHT x 5
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (254, 50))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (258, 46))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (258, 50))+A x 1
    0b00000101, 16, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 16
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (241, 67))+B x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (242, 67))+B x 2
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (245, 68))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (245, 69))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (246, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (247, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (248, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (247, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (247, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (248, 69))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (249, 69))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 70))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (249, 70))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 71))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (249, 71))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 72))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (250, 71))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (252, 72))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (249, 76))+B x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (250, 76))+B x 2
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (247, 81))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (246, 82))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (247, 82))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (248, 81))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (249, 81))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 82))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (249, 82))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 83))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (249, 83))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 84))+A x 1
    0b01000100, 3, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (248, 85))+A x 3
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (247, 88))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (246, 90))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (247, 89))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (249, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (248, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (248, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (249, 89))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (249, 90))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (246, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (245, 89))+A x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (245, 88))+A x 1
    0b00100111, 2, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (244, 87))+B x 2
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (243, 87))+B x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (240, 90))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (238, 87))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (242, 83))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (244, 81))+B x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (245, 82))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (240, 77))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (241, 76))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (242, 76))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (241, 77))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (240, 76))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (241, 75))+A x 2
    0b01000000, 2, // b=4 0100 h=0 0000 HAT_UP (Moveto (242, 73))+A x 2
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (243, 71))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (245, 70))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (243, 76))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (242, 77))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (243, 77))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (244, 76))+A x 1
    0b00100011, 1, // b=2 0010 h=3 0011 HAT_DOWN_RIGHT (Moveto (245, 77))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (246, 77))+B x 1
    0b00000011, 6, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 6
    0b00100011, 1, // b=2 0010 h=3 0011 HAT_DOWN_RIGHT (Moveto (253, 84))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (253, 85))+B x 2
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (258, 84))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (262, 80))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (264, 79))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (263, 80))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (264, 80))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (263, 78))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (262, 76))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (258, 80))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (258, 76))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (262, 72))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (262, 71))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (261, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (262, 68))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (257, 69))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (257, 70))+B x 2
    0b00000011, 6, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 6
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (266, 77))+B x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (268, 74))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (272, 70))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (271, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (272, 68))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (272, 69))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (271, 68))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (270, 69))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (269, 68))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (268, 69))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (269, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (270, 68))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (268, 70))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (268, 68))+A x 1
    0b00000011, 4, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 4
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (272, 74))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (272, 78))+A x 2
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (268, 83))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (266, 81))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (267, 81))+B x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (272, 83))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (268, 87))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (268, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (269, 88))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (268, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (269, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (270, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (271, 88))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (272, 87))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (272, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (271, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (271, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (272, 89))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (272, 90))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (270, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (269, 90))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (268, 90))+A x 1
    0b00000111, 5, // b=0 0000 h=7 0111 HAT_UP_LEFT x 5
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (262, 84))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (258, 88))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (258, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (259, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (258, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (259, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (260, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (261, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (262, 88))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (262, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (261, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (262, 90))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (260, 90))+A x 1
    0b00000001, 15, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 15
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (277, 75))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (277, 76))+B x 2
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (281, 73))+A x 2
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (283, 71))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (285, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (287, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (286, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (286, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (287, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (289, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (288, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (288, 70))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (289, 69))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (289, 70))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (288, 71))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (285, 68))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (283, 67))+B x 3
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (278, 71))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (279, 71))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (278, 72))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (279, 72))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (280, 71))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (280, 72))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (279, 73))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (280, 73))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (281, 72))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (282, 73))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (281, 74))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (282, 74))+A x 1
    0b01000100, 4, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (282, 75))+A x 4
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (278, 82))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (282, 82))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (278, 86))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (278, 87))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (279, 87))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (280, 90))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (283, 87))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (284, 87))+B x 1
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (283, 86))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (285, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (286, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (285, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (285, 90))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (286, 89))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (288, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (287, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (287, 90))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (288, 89))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (289, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (288, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (289, 90))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (292, 87))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 5, // b=4 0100 h=0 0000 HAT_UP (Moveto (292, 83))+A x 5
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (288, 75))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (292, 71))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (292, 75))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (287, 80))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (287, 81))+B x 2
    0b00000111, 8, // b=0 0000 h=7 0111 HAT_UP_LEFT x 8
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (278, 73))+A x 1
    0b00000001, 5, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 5
    0b00000010, 14, // b=0 0000 h=2 0010 HAT_RIGHT x 14
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (298, 68))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (298, 69))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (299, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (300, 68))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (300, 69))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (299, 70))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (300, 70))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (298, 70))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b00100010, 3, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (302, 67))+B x 3
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (306, 68))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (306, 69))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (307, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (308, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (309, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (308, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (308, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (309, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (311, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (310, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (310, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (311, 69))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (312, 69))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (311, 70))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (312, 70))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (307, 74))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (303, 78))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (307, 78))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (303, 82))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (307, 82))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (303, 86))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (307, 86))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (303, 90))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (307, 90))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000000, 11, // b=0 0000 h=0 0000 HAT_UP x 11
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (303, 74))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (302, 71))+B x 1
    0b00000111, 23, // b=0 0000 h=7 0111 HAT_UP_LEFT x 23
    0b00000000, 16, // b=0 0000 h=0 0000 HAT_UP x 16
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (279, 31))+B x 3
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (275, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (274, 29))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (274, 30))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (274, 28))+A x 1
    0b00000101, 37, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 37
    0b00000100, 6, // b=0 0000 h=4 0100 HAT_DOWN x 6
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (237, 72))+B x 3
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 7, // b=0 0000 h=4 0100 HAT_DOWN x 7
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (238, 83))+A x 1
    0b00000111, 12, // b=0 0000 h=7 0111 HAT_UP_LEFT x 12
    0b00000110, 8, // b=0 0000 h=6 0110 HAT_LEFT x 8
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (217, 71))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (217, 72))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (216, 71))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (215, 71))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (214, 70))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (213, 71))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (212, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (213, 69))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (214, 69))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (213, 70))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (212, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (213, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (212, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (211, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (211, 70))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (210, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (211, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (210, 68))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (208, 67))+B x 3
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (208, 71))+B x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (207, 72))+A x 1
    0b01000100, 3, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (207, 73))+A x 3
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (210, 78))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (210, 79))+A x 2
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (212, 81))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (213, 84))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (214, 85))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (213, 86))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (214, 86))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (215, 85))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (216, 85))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (217, 84))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (217, 85))+A x 1
    0b01000101, 5, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (216, 86))+A x 5
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (211, 89))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (212, 88))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (214, 87))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (215, 86))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (216, 87))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (217, 86))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (217, 87))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (214, 90))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (213, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (214, 89))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (213, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (212, 89))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (210, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (211, 88))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (210, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (209, 89))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (207, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (208, 88))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (207, 87))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (206, 88))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (206, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (207, 88))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (208, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (209, 88))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (207, 90))+A x 1
    0b01000110, 2, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (206, 90))+A x 2
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (205, 88))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (203, 87))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (207, 83))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (203, 79))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (207, 79))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (203, 83))+A x 1
    0b00000101, 5, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 5
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (197, 89))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (195, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (196, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (197, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (196, 89))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (194, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (195, 88))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (194, 87))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (193, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (194, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (193, 89))+A x 2
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (193, 90))+A x 2
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (197, 90))+A x 1
    0b00000111, 6, // b=0 0000 h=7 0111 HAT_UP_LEFT x 6
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (190, 83))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (189, 86))+B x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (188, 87))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (189, 87))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (188, 90))+A x 1
    0b00000111, 5, // b=0 0000 h=7 0111 HAT_UP_LEFT x 5
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (182, 84))+A x 1
    0b01000101, 6, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (181, 85))+A x 6
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (175, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (176, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (177, 88))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (178, 87))+A x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (179, 85))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (178, 86))+A x 1
    0b01000000, 2, // b=4 0100 h=0 0000 HAT_UP (Moveto (178, 85))+A x 2
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (176, 81))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (177, 81))+B x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (180, 78))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (181, 78))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (180, 80))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (181, 80))+B x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00100110, 2, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (177, 77))+B x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (174, 79))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (172, 79))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (173, 78))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (174, 78))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (173, 79))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (174, 80))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (172, 83))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (168, 87))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (168, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (169, 88))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (168, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (169, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (170, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (171, 88))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (172, 87))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (172, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (171, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (171, 90))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (172, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (174, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (173, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (173, 90))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (174, 89))+A x 2
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (176, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (175, 90))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (174, 90))+A x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (177, 90))+A x 1
    0b01000001, 5, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (178, 89))+A x 5
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (182, 86))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (181, 87))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (182, 87))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (179, 90))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (178, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (179, 89))+A x 1
    0b00000110, 8, // b=0 0000 h=6 0110 HAT_LEFT x 8
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (170, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (169, 90))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (168, 90))+A x 1
    0b00000000, 6, // b=0 0000 h=0 0000 HAT_UP x 6
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (168, 83))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (168, 79))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (172, 75))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (168, 71))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (172, 71))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (173, 70))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (176, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (175, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (173, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (174, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (173, 68))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (171, 67))+B x 3
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (175, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (176, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (178, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (177, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (177, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (178, 69))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (179, 69))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (178, 70))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (179, 70))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (178, 71))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (179, 71))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (178, 72))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (179, 72))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (180, 71))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (181, 71))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (180, 72))+A x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (178, 73))+A x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (180, 73))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (181, 72))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (182, 72))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (181, 73))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (182, 73))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (182, 74))+A x 1
    0b00000001, 5, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 5
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (188, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (189, 68))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (188, 69))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (189, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (190, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (191, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (190, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (190, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (191, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (193, 68))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (192, 69))+A x 3
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (192, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (193, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (195, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (194, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (194, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (195, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (197, 68))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (196, 69))+A x 3
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (196, 70))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (197, 69))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (197, 70))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (194, 75))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (190, 79))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (194, 79))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (190, 75))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (188, 70))+A x 1
    0b00000011, 6, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 6
    0b00000100, 6, // b=0 0000 h=4 0100 HAT_DOWN x 6
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (194, 83))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (202, 74))+B x 3
    0b00000011, 5, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 5
    0b00000010, 4, // b=0 0000 h=2 0010 HAT_RIGHT x 4
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (212, 77))+B x 2
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (214, 76))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (215, 76))+B x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (214, 77))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (216, 76))+B x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (216, 78))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (217, 78))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (216, 79))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (217, 79))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (217, 80))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (213, 72))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (214, 71))+A x 1
    0b00000101, 5, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 5
    0b00000100, 13, // b=0 0000 h=4 0100 HAT_DOWN x 13
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (209, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (210, 90))+A x 1
    0b00000111, 39, // b=0 0000 h=7 0111 HAT_UP_LEFT x 39
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (170, 50))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (171, 49))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (173, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (172, 49))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (170, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (171, 48))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (170, 48))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (169, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (169, 50))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 2, // b=4 0100 h=0 0000 HAT_UP (Moveto (169, 48))+A x 2
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (172, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (173, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (173, 50))+A x 1
    0b00000001, 5, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 5
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (179, 44))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (177, 41))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (178, 41))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (181, 40))+B x 2
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (180, 37))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (181, 36))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (180, 35))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (179, 36))+A x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (178, 37))+B x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (177, 37))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (179, 35))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (179, 34))+A x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (180, 31))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (179, 30))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (180, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (179, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (178, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (176, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (177, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (178, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (177, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (175, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (176, 28))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (175, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (174, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (174, 30))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (173, 31))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (173, 32))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (175, 30))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (173, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (174, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (173, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (172, 28))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (168, 29))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (168, 30))+B x 2
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (164, 35))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (164, 36))+B x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000100, 4, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (163, 39))+A x 4
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (159, 46))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (159, 47))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (158, 48))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (157, 50))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (158, 49))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (161, 47))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (160, 48))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (159, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (160, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (160, 50))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (163, 47))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (162, 47))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (163, 46))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (158, 41))+B x 1
    0b00100000, 2, // b=2 0010 h=0 0000 HAT_UP (Moveto (158, 40))+B x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (159, 37))+A x 3
    0b01000001, 4, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (160, 34))+A x 4
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (163, 32))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (162, 33))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (163, 33))+A x 1
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (160, 33))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (159, 34))+A x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (159, 33))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (158, 31))+B x 3
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (162, 28))+A x 2
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (163, 29))+A x 2
    0b00000011, 5, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 5
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (169, 36))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (169, 37))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (170, 37))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (169, 38))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (170, 38))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (169, 39))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (169, 43))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (173, 43))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (175, 40))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (174, 37))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (175, 37))+B x 1
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (174, 36))+B x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (179, 31))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (179, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (180, 28))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (178, 30))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (184, 32))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (184, 33))+B x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (182, 36))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (180, 36))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (182, 37))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (183, 36))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (183, 37))+A x 1
    0b00000100, 6, // b=0 0000 h=4 0100 HAT_DOWN x 6
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (183, 44))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (179, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (179, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (180, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (179, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (180, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (181, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (182, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (183, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (183, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (182, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (183, 50))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (181, 50))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000110, 21, // b=0 0000 h=6 0110 HAT_LEFT x 21
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (157, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (156, 49))+A x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (156, 48))+A x 1
    0b00100111, 2, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (155, 47))+B x 2
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (154, 47))+B x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (151, 50))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (149, 47))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (153, 43))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (149, 39))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (153, 35))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (149, 31))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (150, 30))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (153, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (152, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (150, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (151, 28))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (150, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (149, 29))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (149, 30))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (149, 28))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (152, 30))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (153, 29))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (153, 30))+A x 2
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (149, 35))+A x 1
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (153, 39))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (149, 43))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (144, 41))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (144, 42))+B x 2
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 4, // b=4 0100 h=0 0000 HAT_UP (Moveto (143, 39))+A x 4
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (139, 32))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (140, 31))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (139, 30))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (140, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (139, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (138, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (136, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (137, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (138, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (137, 29))+A x 2
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (138, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (139, 29))+A x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (140, 30))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (139, 31))+A x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (141, 31))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (143, 32))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (138, 37))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (138, 38))+B x 2
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000100, 4, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (139, 41))+A x 4
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (135, 48))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (132, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (133, 48))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (134, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (133, 49))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (131, 49))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (132, 48))+A x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (131, 48))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (129, 47))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (131, 50))+A x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (134, 50))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (135, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (137, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (136, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (136, 50))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (137, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (139, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (138, 49))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (138, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (139, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (140, 49))+A x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (141, 48))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (142, 48))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (140, 50))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (139, 50))+A x 1
    0b00000111, 6, // b=0 0000 h=7 0111 HAT_UP_LEFT x 6
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (133, 43))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (129, 39))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (133, 35))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (133, 34))+A x 3
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (134, 31))+B x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (136, 28))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (134, 27))+B x 3
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (128, 32))+B x 3
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b01000111, 2, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (123, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (123, 28))+A x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (123, 30))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (122, 32))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (123, 32))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (123, 33))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (119, 37))+A x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (118, 37))+B x 3
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (114, 37))+B x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000000, 4, // b=4 0100 h=0 0000 HAT_UP (Moveto (113, 35))+A x 4
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (109, 28))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (113, 28))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (108, 33))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (108, 34))+B x 2
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (109, 37))+A x 1
    0b00100011, 1, // b=2 0010 h=3 0011 HAT_DOWN_RIGHT (Moveto (110, 38))+B x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (110, 39))+B x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00100011, 1, // b=2 0010 h=3 0011 HAT_DOWN_RIGHT (Moveto (113, 42))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (113, 43))+B x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (114, 40))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (118, 42))+A x 1
    0b01000100, 3, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (118, 43))+A x 3
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (114, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (114, 50))+A x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (115, 50))+A x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (118, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (118, 50))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00000000, 7, // b=0 0000 h=0 0000 HAT_UP x 7
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (120, 40))+A x 3
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (123, 37))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (119, 33))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (118, 31))+B x 3
    0b00000011, 11, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 11
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (129, 43))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (133, 39))+A x 1
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b00000100, 24, // b=0 0000 h=4 0100 HAT_DOWN x 24
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (136, 67))+B x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (137, 67))+B x 2
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (140, 68))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (140, 69))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (141, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (142, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (143, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (142, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (142, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (143, 69))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (144, 69))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (143, 70))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (144, 70))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (143, 71))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (144, 71))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (143, 72))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (145, 71))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (147, 72))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (143, 76))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (142, 79))+B x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (141, 80))+B x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (140, 81))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (138, 81))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (139, 81))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (138, 82))+A x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (140, 82))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (142, 80))+B x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (142, 83))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (143, 86))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (147, 82))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (146, 81))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (147, 80))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (147, 81))+A x 1
    0b00000100, 4, // b=0 0000 h=4 0100 HAT_DOWN x 4
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (147, 86))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (143, 90))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (147, 90))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00000110, 6, // b=0 0000 h=6 0110 HAT_LEFT x 6
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (137, 87))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (136, 88))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (133, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (134, 88))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (133, 87))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (133, 88))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (134, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (135, 88))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (136, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (137, 88))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (137, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (136, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (137, 90))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (135, 90))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (133, 90))+A x 1
    0b00000000, 6, // b=0 0000 h=0 0000 HAT_UP x 6
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (133, 83))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (137, 79))+A x 1
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (133, 79))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (137, 75))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (137, 74))+A x 3
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (138, 71))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (140, 70))+A x 1
    0b00000011, 6, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 6
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (147, 76))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000110, 10, // b=0 0000 h=6 0110 HAT_LEFT x 10
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (132, 72))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (132, 73))+B x 2
    0b00000111, 5, // b=0 0000 h=7 0111 HAT_UP_LEFT x 5
    0b00000110, 13, // b=0 0000 h=6 0110 HAT_LEFT x 13
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (113, 69))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (113, 70))+B x 2
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (109, 68))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (108, 69))+A x 1
    0b01000100, 3, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (108, 70))+A x 3
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (108, 76))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (109, 77))+A x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (110, 76))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (111, 76))+B x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (108, 79))+B x 1
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (108, 78))+B x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (105, 81))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (106, 81))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (105, 82))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (106, 82))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (107, 81))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (108, 81))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (107, 82))+A x 1
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (107, 83))+B x 3
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (110, 82))+B x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (109, 81))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (112, 83))+A x 1
    0b01000100, 3, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (112, 84))+A x 3
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (108, 90))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (112, 90))+A x 1
    0b00000111, 8, // b=0 0000 h=7 0111 HAT_UP_LEFT x 8
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (103, 81))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (102, 84))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (98, 88))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (98, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (99, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (98, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (99, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (100, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (101, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (102, 88))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (102, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (101, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (102, 90))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (100, 90))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (98, 84))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (98, 80))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (99, 79))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (98, 78))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (99, 78))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (98, 79))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (98, 77))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (102, 73))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (98, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (99, 68))+A x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (100, 68))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (102, 69))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (98, 73))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (93, 78))+B x 1
    0b00100000, 2, // b=2 0010 h=0 0000 HAT_UP (Moveto (93, 77))+B x 2
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (91, 74))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (92, 73))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (92, 74))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (91, 73))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (90, 74))+A x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (88, 75))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (89, 74))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (89, 72))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (88, 73))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (89, 73))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (88, 74))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 4, // b=4 0100 h=0 0000 HAT_UP (Moveto (88, 72))+A x 4
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (89, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (88, 68))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (93, 69))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (93, 70))+B x 2
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (98, 68))+A x 1
    0b00000011, 5, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 5
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (103, 77))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (104, 77))+B x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b00000000, 4, // b=0 0000 h=0 0000 HAT_UP x 4
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (108, 68))+A x 1
    0b00000101, 15, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 15
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (92, 84))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (91, 83))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (92, 82))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (92, 83))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (91, 84))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (92, 85))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (92, 86))+A x 2
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (91, 88))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (88, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (89, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (88, 90))+A x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (90, 90))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (91, 89))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (92, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (91, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (92, 90))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (87, 85))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (87, 86))+B x 2
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (82, 84))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (78, 88))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (78, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (79, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (78, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (79, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (80, 89))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (81, 89))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (82, 88))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (82, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (81, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (82, 90))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (80, 90))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (78, 84))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (82, 80))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (84, 78))+B x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (84, 79))+B x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (87, 81))+B x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (87, 82))+B x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (92, 80))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (92, 81))+A x 1
    0b00000111, 6, // b=0 0000 h=7 0111 HAT_UP_LEFT x 6
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (85, 74))+B x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (85, 75))+B x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (81, 73))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (80, 74))+A x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (78, 75))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (79, 74))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (79, 72))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (78, 73))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (79, 73))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (78, 74))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 4, // b=4 0100 h=0 0000 HAT_UP (Moveto (78, 72))+A x 4
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (79, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (78, 68))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (83, 69))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (83, 70))+B x 2
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (80, 75))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (78, 80))+A x 1
    0b00000101, 7, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 7
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (70, 88))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (69, 90))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (70, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (72, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (71, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (71, 90))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (72, 89))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (72, 90))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (69, 87))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (68, 88))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (69, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (68, 89))+A x 2
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (64, 87))+B x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (63, 87))+B x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (64, 86))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (63, 90))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (68, 87))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (69, 86))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (65, 82))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (69, 78))+A x 1
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (65, 74))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (63, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (64, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (66, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (65, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (63, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (64, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (63, 68))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (65, 70))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (66, 69))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (68, 67))+B x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (69, 67))+B x 2
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (72, 68))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (72, 69))+A x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (70, 71))+B x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (69, 74))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (65, 78))+A x 1
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (69, 82))+A x 1
    0b00000111, 10, // b=0 0000 h=7 0111 HAT_UP_LEFT x 10
    0b00000110, 15, // b=0 0000 h=6 0110 HAT_LEFT x 15
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (43, 72))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (43, 73))+B x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000100, 4, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (42, 76))+A x 4
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (38, 83))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (34, 87))+B x 1
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (33, 86))+B x 1
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (33, 87))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (35, 88))+A x 2
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (35, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (35, 90))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (36, 89))+A x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (38, 88))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (37, 89))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (37, 90))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (38, 89))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (39, 89))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (38, 90))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (39, 90))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (42, 87))+A x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (42, 83))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (37, 78))+B x 1
    0b00100000, 2, // b=2 0010 h=0 0000 HAT_UP (Moveto (37, 77))+B x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (38, 74))+A x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (39, 71))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (38, 70))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (39, 69))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (38, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (37, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (35, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (36, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (37, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (36, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (34, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (35, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (34, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (33, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (31, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (32, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (33, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (32, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (30, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (31, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (30, 68))+A x 1
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (30, 70))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (32, 71))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (33, 70))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (34, 70))+A x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (37, 70))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (38, 69))+A x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (39, 70))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (38, 71))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (32, 75))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (28, 79))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (32, 79))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (28, 83))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (32, 83))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (28, 87))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (30, 90))+A x 1
    0b00000111, 12, // b=0 0000 h=7 0111 HAT_UP_LEFT x 12
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (17, 78))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (13, 82))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (17, 82))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (13, 86))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (17, 86))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (13, 90))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (17, 90))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00000000, 7, // b=0 0000 h=0 0000 HAT_UP x 7
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (13, 78))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (17, 74))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (18, 71))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (20, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (22, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (21, 69))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (21, 70))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (22, 69))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (22, 70))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (20, 68))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (18, 67))+B x 3
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (14, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (12, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (13, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (14, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (13, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (11, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (12, 68))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (11, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (10, 69))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (8, 69))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (9, 68))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (10, 68))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (9, 69))+A x 2
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (10, 70))+A x 2
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (8, 68))+A x 1
    0b00000011, 5, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 5
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (13, 74))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b00000010, 11, // b=0 0000 h=2 0010 HAT_RIGHT x 11
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (28, 71))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (28, 75))+A x 1
    0b00000111, 23, // b=0 0000 h=7 0111 HAT_UP_LEFT x 23
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (4, 51))+B x 1
    0b00100110, 2, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (3, 51))+B x 2
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (1, 47))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (5, 43))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (8, 40))+A x 1
    0b01000010, 3, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (9, 40))+A x 3
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (15, 36))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (15, 35))+A x 3
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (16, 31))+B x 3
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (12, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (11, 29))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (11, 30))+A x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (10, 33))+B x 2
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (9, 35))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (10, 35))+B x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (8, 35))+B x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (7, 34))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (6, 35))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (7, 35))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (6, 36))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (5, 35))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (6, 34))+A x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (6, 33))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (5, 31))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (4, 30))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (5, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (4, 28))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (3, 29))+A x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (1, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (2, 29))+A x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (2, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (1, 29))+A x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (1, 28))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (3, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (4, 29))+A x 2
    0b00000100, 1, // b=0 0000 h=4 0100 HAT_DOWN x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (5, 30))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (1, 35))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (1, 39))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (5, 39))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (7, 38))+B x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (6, 37))+A x 1
    0b00000101, 5, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 5
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (1, 43))+A x 1
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (5, 47))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (11, 44))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (15, 40))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (15, 44))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (11, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (11, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (12, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (11, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (12, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (13, 49))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (14, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (15, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (15, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (14, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (15, 50))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (13, 50))+A x 1
    0b00000001, 7, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 7
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (21, 43))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (25, 39))+A x 1
    0b01000000, 4, // b=4 0100 h=0 0000 HAT_UP (Moveto (25, 38))+A x 4
    0b00000111, 3, // b=0 0000 h=7 0111 HAT_UP_LEFT x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (21, 31))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (25, 27))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (26, 27))+B x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (24, 27))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (28, 28))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (28, 29))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (29, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (30, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (31, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (30, 29))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (30, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (31, 29))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (32, 29))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (31, 30))+A x 1
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (33, 30))+B x 2
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b01000100, 5, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (35, 34))+A x 5
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (31, 42))+A x 1
    0b00000010, 3, // b=0 0000 h=2 0010 HAT_RIGHT x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (35, 42))+A x 1
    0b00000101, 3, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 3
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (31, 46))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (31, 47))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (30, 48))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (27, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (28, 48))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (29, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (28, 49))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (26, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (27, 48))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (26, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (25, 49))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (23, 49))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (24, 48))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (25, 48))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (24, 49))+A x 2
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (25, 50))+A x 2
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (23, 48))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (21, 47))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (25, 43))+A x 1
    0b00000111, 4, // b=0 0000 h=7 0111 HAT_UP_LEFT x 4
    0b00100111, 1, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (20, 38))+B x 1
    0b00100000, 2, // b=2 0010 h=0 0000 HAT_UP (Moveto (20, 37))+B x 2
    0b00000001, 5, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 5
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (26, 31))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (28, 30))+A x 1
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000100, 2, // b=0 0000 h=4 0100 HAT_DOWN x 2
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (30, 35))+B x 3
    0b00000011, 5, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 5
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (35, 46))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (34, 47))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (35, 47))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (33, 47))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (32, 48))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (31, 50))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (32, 49))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (31, 48))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (32, 47))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (30, 49))+A x 2
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (32, 50))+A x 1
    0b00000001, 8, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 8
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (41, 41))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (45, 37))+A x 1
    0b01000000, 3, // b=4 0100 h=0 0000 HAT_UP (Moveto (45, 36))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (44, 33))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (45, 33))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (46, 31))+B x 3
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (42, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (41, 29))+A x 1
    0b01000100, 3, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (41, 30))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (42, 32))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (40, 34))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (40, 35))+B x 2
    0b00000011, 4, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 4
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (45, 41))+A x 1
    0b00000001, 2, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 2
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (48, 38))+A x 3
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (49, 35))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (50, 34))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (49, 33))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (48, 34))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (49, 34))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (50, 33))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (48, 35))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (48, 36))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (49, 36))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (50, 35))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (48, 37))+A x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (49, 38))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (50, 37))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (50, 38))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (49, 39))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (49, 40))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (50, 39))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (50, 40))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (49, 41))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (49, 42))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (50, 41))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (50, 42))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (49, 43))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (49, 44))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (50, 43))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (50, 44))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (49, 45))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (50, 45))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00100001, 1, // b=2 0010 h=1 0001 HAT_UP_RIGHT (Moveto (52, 43))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (52, 44))+B x 2
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b00100101, 1, // b=2 0010 h=5 0101 HAT_DOWN_LEFT (Moveto (50, 47))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (50, 48))+B x 2
    0b00000110, 2, // b=0 0000 h=6 0110 HAT_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (47, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (46, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (47, 50))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b01000110, 2, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (45, 50))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (43, 49))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (43, 50))+A x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (48, 45))+A x 1
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (46, 45))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (48, 43))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (48, 41))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (48, 39))+A x 1
    0b00000001, 4, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 4
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (53, 34))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (57, 30))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (56, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (57, 28))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (57, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (56, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (55, 29))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (54, 28))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (53, 29))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (54, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (55, 28))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (53, 30))+A x 1
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (53, 28))+A x 1
    0b00000101, 4, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 4
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (48, 33))+A x 1
    0b00000011, 4, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 4
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (53, 38))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (57, 34))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (57, 38))+A x 1
    0b00000100, 3, // b=0 0000 h=4 0100 HAT_DOWN x 3
    0b01000100, 4, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (57, 42))+A x 4
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (55, 47))+A x 1
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (55, 48))+A x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (54, 50))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (55, 50))+A x 1
    0b00000001, 9, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 9
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (64, 37))+A x 1
    0b01000001, 4, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (65, 36))+A x 4
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (67, 32))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (68, 31))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (68, 32))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (67, 33))+A x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (66, 33))+A x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (68, 34))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (67, 35))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (68, 35))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (65, 37))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (64, 36))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00000000, 3, // b=0 0000 h=0 0000 HAT_UP x 3
    0b00100000, 3, // b=2 0010 h=0 0000 HAT_UP (Moveto (63, 31))+B x 3
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (67, 28))+A x 2
    0b01000100, 2, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (68, 29))+A x 2
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b00000010, 2, // b=0 0000 h=2 0010 HAT_RIGHT x 2
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (73, 32))+B x 1
    0b00100100, 2, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (73, 33))+B x 2
    0b00000011, 2, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (76, 36))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (77, 35))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (78, 35))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (77, 36))+A x 2
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (77, 37))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (78, 36))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (79, 36))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (78, 37))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (79, 37))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (80, 36))+A x 1
    0b00100011, 1, // b=2 0010 h=3 0011 HAT_DOWN_RIGHT (Moveto (81, 37))+B x 1
    0b00100010, 1, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (82, 37))+B x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (84, 35))+A x 1
    0b01000010, 2, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (85, 35))+A x 2
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (87, 34))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (88, 34))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (87, 35))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (88, 35))+A x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b01000000, 2, // b=4 0100 h=0 0000 HAT_UP (Moveto (88, 32))+A x 2
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (86, 30))+B x 1
    0b01000111, 2, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (85, 29))+A x 2
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (83, 29))+A x 2
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (81, 29))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (82, 28))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (83, 28))+A x 1
    0b01000101, 2, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (82, 29))+A x 2
    0b00000010, 1, // b=0 0000 h=2 0010 HAT_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (83, 30))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (84, 29))+A x 2
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (83, 31))+B x 3
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b00000110, 1, // b=0 0000 h=6 0110 HAT_LEFT x 1
    0b00100110, 1, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (79, 31))+B x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (78, 32))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (78, 33))+A x 1
    0b00000001, 3, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 3
    0b00000000, 1, // b=0 0000 h=0 0000 HAT_UP x 1
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (81, 28))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b00100110, 3, // b=2 0010 h=6 0110 HAT_LEFT (Moveto (79, 27))+B x 3
    0b00000011, 3, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 3
    0b00000100, 10, // b=0 0000 h=4 0100 HAT_DOWN x 10
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (80, 41))+B x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (81, 42))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (82, 42))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (83, 41))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (84, 41))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (83, 42))+A x 1
    0b00100100, 3, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (83, 43))+B x 3
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (84, 47))+A x 1
    0b01000101, 3, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (83, 48))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (82, 50))+A x 1
    0b01000001, 3, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (83, 49))+A x 3
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (86, 47))+A x 1
    0b01000001, 2, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (87, 46))+A x 2
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (88, 46))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (87, 47))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (88, 47))+A x 1
    0b00000101, 2, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 2
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (85, 50))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (84, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (85, 48))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (85, 49))+A x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (84, 50))+A x 1
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (83, 50))+A x 1
    0b00000111, 1, // b=0 0000 h=7 0111 HAT_UP_LEFT x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (81, 48))+A x 1
    0b00100111, 2, // b=2 0010 h=7 0111 HAT_UP_LEFT (Moveto (80, 47))+B x 2
    0b00100100, 1, // b=2 0010 h=4 0100 HAT_DOWN (Moveto (79, 47))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000011, 1, // b=4 0100 h=3 0011 HAT_DOWN_RIGHT (Moveto (81, 49))+A x 1
    0b01000001, 1, // b=4 0100 h=1 0001 HAT_UP_RIGHT (Moveto (82, 48))+A x 1
    0b00000101, 1, // b=0 0000 h=5 0101 HAT_DOWN_LEFT x 1
    0b01000101, 1, // b=4 0100 h=5 0101 HAT_DOWN_LEFT (Moveto (80, 50))+A x 1
    0b00000110, 3, // b=0 0000 h=6 0110 HAT_LEFT x 3
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (76, 50))+A x 1
    0b00000111, 2, // b=0 0000 h=7 0111 HAT_UP_LEFT x 2
    0b01000000, 1, // b=4 0100 h=0 0000 HAT_UP (Moveto (74, 47))+A x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (75, 47))+A x 1
    0b01000111, 1, // b=4 0100 h=7 0111 HAT_UP_LEFT (Moveto (74, 46))+A x 1
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000000, 2, // b=0 0000 h=0 0000 HAT_UP x 2
    0b00100000, 1, // b=2 0010 h=0 0000 HAT_UP (Moveto (75, 42))+B x 1
    0b00100010, 2, // b=2 0010 h=2 0010 HAT_RIGHT (Moveto (76, 42))+B x 2
    0b00000001, 1, // b=0 0000 h=1 0001 HAT_UP_RIGHT x 1
    0b00000010, 6, // b=0 0000 h=2 0010 HAT_RIGHT x 6
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (85, 41))+A x 1
    0b00100011, 1, // b=2 0010 h=3 0011 HAT_DOWN_RIGHT (Moveto (86, 42))+B x 1
    0b00000011, 1, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 1
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (88, 43))+A x 1
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (88, 44))+A x 1
    0b00000111, 16, // b=0 0000 h=7 0111 HAT_UP_LEFT x 16
    0b00000110, 30, // b=0 0000 h=6 0110 HAT_LEFT x 30
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (41, 28))+A x 1
    0b00000100, 16, // b=0 0000 h=4 0100 HAT_DOWN x 16
    0b01000100, 1, // b=4 0100 h=4 0100 HAT_DOWN (Moveto (41, 45))+A x 1
    0b00000111, 17, // b=0 0000 h=7 0111 HAT_UP_LEFT x 17
    0b00000110, 12, // b=0 0000 h=6 0110 HAT_LEFT x 12
    0b01000110, 1, // b=4 0100 h=6 0110 HAT_LEFT (Moveto (11, 28))+A x 1
    0b00000011, 47, // b=0 0000 h=3 0011 HAT_DOWN_RIGHT x 47
    0b00000010, 109, // b=0 0000 h=2 0010 HAT_RIGHT x 109
    0b01000010, 1, // b=4 0100 h=2 0010 HAT_RIGHT (Moveto (168, 75))+A x 1
    0b01110111, 1, // b=7 0111 h=7 0111 HAT_UP_LEFT+R x 1
    0b00000111, 7, // b=0 0000 h=7 0111 HAT_UP_LEFT x 7
    0b00000000, 7, // b=0 0000 h=0 0000 HAT_UP x 7
 0 };
static int numsteps = 2865;
