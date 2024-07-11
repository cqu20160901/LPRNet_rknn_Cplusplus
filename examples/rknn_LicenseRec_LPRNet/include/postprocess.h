#ifndef _POSTPROCESS_H_
#define _POSTPROCESS_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <vector>

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

typedef signed char int8_t;
typedef unsigned int uint32_t;

class LPRNet
{
public:
    LPRNet();

    ~LPRNet();

    int GetRecongitionResult(int8_t **PtrOutput, std::vector<int> &qnt_zp, std::vector<float> &qnt_scale, std::string &LicenseResult);

    /***
     CHARS = [ "¾©", "»¦", "½ò", "Óå", "¼½", "½ú", "ÃÉ", "ÁÉ", "¼ª", "ºÚ",
                  "ËÕ", "Õã", "Íî", "Ãö", "¸Ó", "Â³", "Ô¥", "¶õ", "Ïæ", "ÔÁ",
                  "¹ð", "Çí", "´¨", "¹ó", "ÔÆ", "²Ø", "ÉÂ", "¸Ê", "Çà", "Äþ",
                  "ÐÂ",
                  "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                  "A", "B", "C", "D", "E", "F", "G", "H", "J", "K",
                  "L", "M", "N", "P", "Q", "R", "S", "T", "U", "V",
                  "W", "X", "Y", "Z", "I", "O", "-" ]

    ***/

    std::vector<std::string> CHARS = {"BJ", "SH", "TJ", "CQ", "HB", "SN", "NM", "LN", "JN", "HL",
                                      "JS", "ZJ", "AH", "FJ", "JX", "SD", "HA", "HB", "HN", "GD",
                                      "GL", "HI", "SC", "GZ", "YN", "XZ", "SX", "GS", "QH", "NX",
                                      "XJ",
                                      "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                                      "A", "B", "C", "D", "E", "F", "G", "H", "J", "K",
                                      "L", "M", "N", "P", "Q", "R", "S", "T", "U", "V",
                                      "W", "X", "Y", "Z", "I", "O", "-"};

    int OutputChannel_ = 68;
    int OutputHeight_ = 18;
    int OutputWidth_ = 1;
};

#endif
