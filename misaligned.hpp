#ifndef MISALIGNED_H_
#define MISALIGNED_H_

enum MajorColor {

    WHITE = 0,
    RED,
    BLACK,
    YELLOW,
    VIOLET
};

enum MinorColor {

    BLUE = 0,
    ORANGE,
    GREEN,
    BROWN,
    SLATE
};

#define ColorNum_To_PairNum(majorColor, minorColor, maxMinorColor) (majorColor * maxMinorColor + minorColor + 1)
#define MAX_WIDTH 12 // user for setting width parameter

#define PairNum_To_MajorColor(pairNum, maxMinorColor) ((MajorColor) ((pairNum - 1) / maxMinorColor))
#define PairNum_To_MinorColor(pairNum, maxMinorColor) ((MinorColor) ((pairNum - 1) % maxMinorColor))

#endif // MISALIGNED_H_