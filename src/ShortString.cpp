#include "sheer/ShortString.hpp"

namespace sheer
{

const std::array<ShortString::SChar,128> ShortString::toSChar = {
    0, //0
    0, //1
    0, //2
    0, //3
    0, //4
    0, //5
    0, //6
    0, //7
    0, //8
    0, //9
    0, //10
    0, //11
    0, //12
    0, //13
    0, //14
    0, //15
    0, //16
    0, //17
    0, //18
    0, //19
    0, //20
    0, //21
    0, //22
    0, //23
    0, //24
    0, //25
    0, //26
    0, //27
    0, //28
    0, //29
    0, //30
    0, //31
    0, //32
    0, //33
    0, //34
    0, //35
    0, //36
    0, //37
    0, //38
    0, //39
    0, //40
    0, //41
    0, //42
    0, //43
    0, //44
    0, //45
    0, //46
    0, //47
    1, //48 = 0
    2, //49 = 1
    3, //50 = 2
    4, //51 = 3
    5, //52 = 4
    6, //53 = 5
    7, //54 = 6
    8, //55 = 7
    9, //56 = 8
    10, //57 = 9
    0, //58
    0, //59
    0, //60
    0, //61
    0, //62
    0, //63
    0, //64
    11, //65 = A
    12, //66 = B
    13, //67 = C
    14, //68 = D
    15, //69 = E
    16, //70 = F
    17, //71 = G
    18, //72 = H
    19, //73 = I
    20, //74 = J
    21, //75 = K
    22, //76 = L
    23, //77 = M
    24, //78 = N
    25, //79 = O
    26, //80 = P
    27, //81 = Q
    28, //82 = R
    29, //83 = S
    30, //84 = T
    31, //85 = U
    32, //86 = V
    33, //87 = W
    34, //88 = X
    35, //89 = Y
    36, //90 = Z
    0, //91
    0, //92
    0, //93
    0, //94
    37, //95 = _
    0, //96
    38, //97 = a
    39, //98 = b
    40, //99 = c
    41, //100 = d
    42, //101 = e
    43, //102 = f
    44, //103 = g
    45, //104 = h
    46, //105 = i
    47, //106 = j
    48, //107 = k
    49, //108 = l
    50, //109 = m
    51, //110 = n
    52, //111 = o
    53, //112 = p
    54, //113 = q
    55, //114 = r
    56, //115 = s
    57, //116 = t
    58, //117 = u
    59, //118 = v
    60, //119 = w
    61, //120 = x
    62, //121 = y
    63, //122 = z
    0, //123
    0, //124
    0, //125
    0, //126
    0, //127
};

const std::array<char,64> ShortString::toChar = {
    32, //0
    48, //1 = 0
    49, //2 = 1
    50, //3 = 2
    51, //4 = 3
    52, //5 = 4
    53, //6 = 5
    54, //7 = 6
    55, //8 = 7
    56, //9 = 8
    57, //10 = 9
    65, //11 = A
    66, //12 = B
    67, //13 = C
    68, //14 = D
    69, //15 = E
    70, //16 = F
    71, //17 = G
    72, //18 = H
    73, //19 = I
    74, //20 = J
    75, //21 = K
    76, //22 = L
    77, //23 = M
    78, //24 = N
    79, //25 = O
    80, //26 = P
    81, //27 = Q
    82, //28 = R
    83, //29 = S
    84, //30 = T
    85, //31 = U
    86, //32 = V
    87, //33 = W
    88, //34 = X
    89, //35 = Y
    90, //36 = Z
    95, //37 = _
    97, //38 = a
    98, //39 = b
    99, //40 = c
    100, //41 = d
    101, //42 = e
    102, //43 = f
    103, //44 = g
    104, //45 = h
    105, //46 = i
    106, //47 = j
    107, //48 = k
    108, //49 = l
    109, //50 = m
    110, //51 = n
    111, //52 = o
    112, //53 = p
    113, //54 = q
    114, //55 = r
    115, //56 = s
    116, //57 = t
    117, //58 = u
    118, //59 = v
    119, //60 = w
    120, //61 = x
    121, //62 = y
    122, //63 = z
};

}
