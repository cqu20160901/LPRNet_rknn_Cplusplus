#include "postprocess.h"

LPRNet::LPRNet()
{
}

LPRNet::~LPRNet()
{
}

int LPRNet::GetRecongitionResult(int8_t **PtrBlob, std::vector<int> &qnt_zp, std::vector<float> &qnt_scale, std::string &LicenseResult)
{
    int ret = 0;
    int8_t *Output = (int8_t *)PtrBlob[0];

    float TempValue = 0;
    int MaxValueH = 0;

    std::vector<int> ArgmaxResult;

    for (int h = 0; h < OutputHeight_; h++)
    {
        for (int c = 0; c < OutputChannel_; c++)
        {
            if (0 == c)
            {
                TempValue = Output[c * OutputHeight_ + h];
                MaxValueH = c;
            }
            else
            {
                if (TempValue < Output[c * OutputHeight_ + h])
                {
                    TempValue = Output[c * OutputHeight_ + h];
                    MaxValueH = c;
                }
            }
        }

        ArgmaxResult.push_back(MaxValueH);
    }

    int PreC = ArgmaxResult[0];
    std::vector<int> Result;
    if (PreC != CHARS.size() - 1)
    {
        Result.push_back(PreC);
    }

    for (auto Val : ArgmaxResult)
    {
        if (PreC == Val || Val == CHARS.size() - 1)
        {
            if (Val == CHARS.size() - 1)
            {
                PreC = Val;
            }
            continue;
        }
        Result.push_back(Val);
        PreC = Val;
    }

    for (auto Val : Result)
    {
        LicenseResult += CHARS[Val];
    }
    return ret;
}