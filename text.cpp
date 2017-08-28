#include "text.h"

int32_t text::int32Pow(int32_t base, int32_t exp)
{
    int32_t out=1;
    for(int32_t i=0;i<exp;i++)
        out=out*base;
    return out;
}

int64_t text::int64Pow(int64_t base, int64_t exp)
{
    int64_t out=1;
    for(int64_t i=0;i<exp;i++)
        out=out*base;
    return out;
}

uint32_t text::uint32Pow(uint32_t base, uint32_t exp)
{
    uint32_t out=1;
    for(uint32_t i=0;i<exp;i++)
        out=out*base;
    return out;
}

uint64_t text::uint64Pow(uint64_t base, uint64_t exp)
{
    uint64_t out=1;
    for(uint64_t i=0;i<exp;i++)
        out=out*base;
    return out;
}

char *text::mkstr(size_t length)
{
    char *out=(char*)malloc(length+1); // Zero-terminator
    out[length]=0;
    return out;
}

wchar_t *text::mkwstr(size_t length)
{
    wchar_t *out=(wchar_t*)malloc((length+1)*sizeof(wchar_t)); // Zero-terminator
    out[length]=0;
    return out;
}

char *text::duplicateString(const char *in)
{
    return strdup(in);
}

char *text::terminateFixedLengthString(const char *in, size_t length)
{
    char *newString=(char*)malloc(length+1);
    memcpy(newString,in,length);
    newString[length]=0;
    return newString;
}
char *text::concat(const char *part1, const char *part2)
{
    size_t part1Len=strlen(part1);
    size_t part2Len=strlen(part2);
    char *out=mkstr(part1Len+part2Len);
    memcpy(out,part1,part1Len);
    memcpy(out+part1Len,part2,part2Len);
    return out;
}

char *text::concat(const char *part1, const char *part2, const char *part3)
{
    size_t part1Len=strlen(part1);
    size_t part2Len=strlen(part2);
    size_t part3Len=strlen(part3);
    char *out=mkstr(part1Len+part2Len+part3Len);
    memcpy(out,part1,part1Len);
    memcpy(out+part1Len,part2,part2Len);
    memcpy(out+part1Len+part2Len,part3,part3Len);
    return out;
}

char *text::concat(const char *part1, const char *part2, const char *part3, const char *part4)
{
    size_t part1Len=strlen(part1);
    size_t part2Len=strlen(part2);
    size_t part3Len=strlen(part3);
    size_t part4Len=strlen(part4);
    char *out=mkstr(part1Len+part2Len+part3Len+part4Len);
    memcpy(out,part1,part1Len);
    memcpy(out+part1Len,part2,part2Len);
    memcpy(out+part1Len+part2Len,part3,part3Len);
    memcpy(out+part1Len+part2Len+part3Len,part4,part4Len);
    return out;
}

char *text::concat(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5)
{
    size_t part1Len=strlen(part1);
    size_t part2Len=strlen(part2);
    size_t part3Len=strlen(part3);
    size_t part4Len=strlen(part4);
    size_t part5Len=strlen(part5);
    char *out=mkstr(part1Len+part2Len+part3Len+part4Len+part5Len);
    memcpy(out,part1,part1Len);
    memcpy(out+part1Len,part2,part2Len);
    memcpy(out+part1Len+part2Len,part3,part3Len);
    memcpy(out+part1Len+part2Len+part3Len,part4,part4Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len,part5,part5Len);
    return out;
}

char *text::concat(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5, const char *part6)
{
    size_t part1Len=strlen(part1);
    size_t part2Len=strlen(part2);
    size_t part3Len=strlen(part3);
    size_t part4Len=strlen(part4);
    size_t part5Len=strlen(part5);
    size_t part6Len=strlen(part6);
    char *out=mkstr(part1Len+part2Len+part3Len+part4Len+part5Len+part6Len);
    memcpy(out,part1,part1Len);
    memcpy(out+part1Len,part2,part2Len);
    memcpy(out+part1Len+part2Len,part3,part3Len);
    memcpy(out+part1Len+part2Len+part3Len,part4,part4Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len,part5,part5Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len+part5Len,part6,part6Len);
    return out;
}

char *text::concat(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5, const char *part6, const char *part7)
{
    size_t part1Len=strlen(part1);
    size_t part2Len=strlen(part2);
    size_t part3Len=strlen(part3);
    size_t part4Len=strlen(part4);
    size_t part5Len=strlen(part5);
    size_t part6Len=strlen(part6);
    size_t part7Len=strlen(part7);
    char *out=mkstr(part1Len+part2Len+part3Len+part4Len+part5Len+part6Len+part7Len);
    memcpy(out,part1,part1Len);
    memcpy(out+part1Len,part2,part2Len);
    memcpy(out+part1Len+part2Len,part3,part3Len);
    memcpy(out+part1Len+part2Len+part3Len,part4,part4Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len,part5,part5Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len+part5Len,part6,part6Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len+part5Len+part6Len,part7,part7Len);
    return out;
}

char *text::concat(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5, const char *part6, const char *part7, const char *part8)
{
    size_t part1Len=strlen(part1);
    size_t part2Len=strlen(part2);
    size_t part3Len=strlen(part3);
    size_t part4Len=strlen(part4);
    size_t part5Len=strlen(part5);
    size_t part6Len=strlen(part6);
    size_t part7Len=strlen(part7);
    size_t part8Len=strlen(part8);
    char *out=mkstr(part1Len+part2Len+part3Len+part4Len+part5Len+part6Len+part7Len+part8Len);
    memcpy(out,part1,part1Len);
    memcpy(out+part1Len,part2,part2Len);
    memcpy(out+part1Len+part2Len,part3,part3Len);
    memcpy(out+part1Len+part2Len+part3Len,part4,part4Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len,part5,part5Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len+part5Len,part6,part6Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len+part5Len+part6Len,part7,part7Len);
    memcpy(out+part1Len+part2Len+part3Len+part4Len+part5Len+part6Len+part7Len,part8,part8Len);
    return out;
}

wchar_t *text::concatWideString(const wchar_t *part1, const wchar_t *part2)
{
    size_t part1Len=wcslen(part1);
    size_t part2Len=wcslen(part2);
    wchar_t *out=(wchar_t*)mkwstr(part1Len+part2Len);
    wmemcpy(out,part1,part1Len);
    wmemcpy(out+part1Len,part2,part2Len);
    return out;
}

wchar_t *text::concatWideString(const wchar_t *part1, const wchar_t *part2, const wchar_t *part3)
{
    size_t part1Len=wcslen(part1);
    size_t part2Len=wcslen(part2);
    size_t part3Len=wcslen(part3);
    wchar_t *out=(wchar_t*)mkwstr(part1Len+part2Len+part3Len);
    wmemcpy(out,part1,part1Len);
    wmemcpy(out+part1Len,part2,part2Len);
    wmemcpy(out+part1Len+part2Len,part3,part3Len);
    return out;
}

wchar_t *text::concatWideString(const wchar_t *part1, const wchar_t *part2, const wchar_t *part3, const wchar_t *part4)
{
    size_t part1Len=wcslen(part1);
    size_t part2Len=wcslen(part2);
    size_t part3Len=wcslen(part3);
    size_t part4Len=wcslen(part4);
    wchar_t *out=(wchar_t*)mkwstr(part1Len+part2Len+part3Len+part4Len);
    wmemcpy(out,part1,part1Len);
    wmemcpy(out+part1Len,part2,part2Len);
    wmemcpy(out+part1Len+part2Len,part3,part3Len);
    wmemcpy(out+part1Len+part2Len+part3Len,part4,part4Len);
    return out;
}

char *text::concatPaths(const char *part1, const char *part2)
{
    if(part1[0]=='\\')
        part1++;
    return concat(part1,part1[strlen(part1)-1]=='\\'?"":"\\",part2);
}

char *text::concatPaths(const char *part1, const char *part2, const char *part3)
{
    if(part1[0]=='\\')
        part1++;
    if(part2[0]=='\\')
        part2++;
    return concat(part1,part1[strlen(part1)-1]=='\\'?"":"\\",part2,part2[strlen(part2)-1]=='\\'?"":"\\",part3);
}

char *text::concatPaths(const char *part1, const char *part2, const char *part3, const char *part4)
{
    if(part1[0]=='\\')
        part1++;
    if(part2[0]=='\\')
        part2++;
    if(part3[0]=='\\')
        part3++;
    if(part4[0]=='\\')
        part4++;
    return concat(part1,part1[strlen(part1)-1]=='\\'?"":"\\",part2,part2[strlen(part2)-1]=='\\'?"":"\\",part3,part3[strlen(part3)-1]=='\\'?"":"\\",part4);
}

char *text::concatPaths(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5)
{
    if(part1[0]=='\\')
        part1++;
    if(part2[0]=='\\')
        part2++;
    if(part3[0]=='\\')
        part3++;
    if(part4[0]=='\\')
        part4++;
    if(part5[0]=='\\')
        part5++;
    return concat(part1,part1[strlen(part1)-1]=='\\'?"":"\\",part2,part2[strlen(part2)-1]=='\\'?"":"\\",part3,part3[strlen(part3)-1]=='\\'?"":"\\",part4,text::concat(part4[strlen(part4)-1]=='\\'?"":"\\",part5));
}

char *text::concatPaths(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5, const char *part6)
{
    if(part1[0]=='\\')
        part1++;
    if(part2[0]=='\\')
        part2++;
    if(part3[0]=='\\')
        part3++;
    if(part4[0]=='\\')
        part4++;
    if(part5[0]=='\\')
        part5++;
    if(part6[0]=='\\')
        part6++;
    return concat(part1,part1[strlen(part1)-1]=='\\'?"":"\\",part2,part2[strlen(part2)-1]=='\\'?"":"\\",part3,part3[strlen(part3)-1]=='\\'?"":"\\",part4,text::concat(part4[strlen(part4)-1]=='\\'?"":"\\",part5,part5[strlen(part5)-1]=='\\'?"":"\\",part6));
}

char *text::concatPaths(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5, const char *part6, const char *part7)
{
    if(part1[0]=='\\')
        part1++;
    if(part2[0]=='\\')
        part2++;
    if(part3[0]=='\\')
        part3++;
    if(part4[0]=='\\')
        part4++;
    if(part5[0]=='\\')
        part5++;
    if(part6[0]=='\\')
        part6++;
    if(part7[0]=='\\')
        part7++;
    return concat(part1,part1[strlen(part1)-1]=='\\'?"":"\\",part2,part2[strlen(part2)-1]=='\\'?"":"\\",part3,part3[strlen(part3)-1]=='\\'?"":"\\",text::concat(part4,part4[strlen(part4)-1]=='\\'?"":"\\",part5,part5[strlen(part5)-1]=='\\'?"":"\\",part6,part6[strlen(part6)-1]=='\\'?"":"\\",part7));
}

char *text::concatPaths(const char *part1, const char *part2, const char *part3, const char *part4, const char *part5, const char *part6, const char *part7, const char *part8)
{
    if(part1[0]=='\\')
        part1++;
    if(part2[0]=='\\')
        part2++;
    if(part3[0]=='\\')
        part3++;
    if(part4[0]=='\\')
        part4++;
    if(part5[0]=='\\')
        part5++;
    if(part6[0]=='\\')
        part6++;
    if(part7[0]=='\\')
        part7++;
    if(part8[0]=='\\')
        part8++;
    return concat(part1,part1[strlen(part1)-1]=='\\'?"":"\\",part2,part2[strlen(part2)-1]=='\\'?"":"\\",part3,part3[strlen(part3)-1]=='\\'?"":"\\",text::concat(part4,part4[strlen(part4)-1]=='\\'?"":"\\",part5,part5[strlen(part5)-1]=='\\'?"":"\\",part6,part6[strlen(part6)-1]=='\\'?"":"\\",part7,text::concat(part7[strlen(part7)-1]=='\\'?"":"\\",part8)));
}

char *text::toString(int32_t in)
{
    return intToString(in);
}

char *text::toString(int64_t in)
{
    return longToString(in);
}

char *text::toString(uint32_t in)
{
    return unsignedIntToString(in);
}

char *text::toString(uint64_t in)
{
    return unsignedLongToString(in);
}

char *text::toString(double in)
{
    return doubleToString(in);
}

char *text::toString(double in, uint8_t precision)
{
    return doubleToStringWithFixedPrecision(in,precision);
}

char *text::intToString(int32_t in)
{
    if(in<0)
    {
        char *u=unsignedIntToString(-in);
        char *ret=text::concat("-",u);
        free(u);
        return ret;
    }
    return unsignedIntToString(in);
}

char *text::longToString(int64_t in)
{
    if(in<0)
    {
        char *u=unsignedLongToString(-in);
        char *ret=text::concat("-",u);
        free(u);
        return ret;
    }
    return unsignedLongToString(in);
}

char *text::doubleToString(double in) // Warning: precision loss (inavoidable)
{
    // Modify doubleToStringWithFixedPrecision, too.
    double i,f;
    f=modf(in,&i);
    bool negative=in<0.0;
    // This works both when i is negative and when f is negative (both can be negative).
    if(f<0.0)
        f*=-1.0;
    if(i<0.0)
        i*=-1.0;
    char *iStr=unsignedLongToString((uint64_t)i);
    char *fStr=unsignedLongToString(roundl((f*pow((double)10,15))/10.0)); // Precision loss inavoidable.
    int iStrLen=strlen(iStr);
    int fStrLen=strlen(fStr);
    uint8_t emptyDecimals=f==0.0?0:(uint8_t)((double)(floor(log10((double)f))+1)*-1.0);
    if(emptyDecimals>0)
    {
        // Prepend empty decimals
        char *zeroString=mkstr(emptyDecimals);
        memset(zeroString,'0',emptyDecimals);
        char *nStr=concat(zeroString,fStr);
        free(fStr);
        fStr=nStr;
        fStrLen+=emptyDecimals;
        free(zeroString);
    }
    while(fStr[fStrLen-1]=='0'&&fStrLen>1)
        fStrLen--;
    if(negative)
    {
        char *out=(char*)malloc(iStrLen+fStrLen+3+emptyDecimals); // Zero-terminator, "-" and "."
        out[0]='-';
        memcpy(out+1,iStr,iStrLen);
        out[iStrLen+1]='.';
        memcpy(out+iStrLen+2,fStr,fStrLen);
        out[iStrLen+fStrLen+2]=0;
        free(fStr);
        free(iStr);
        return out;
    }
    char *out=(char*)malloc(iStrLen+fStrLen+2+emptyDecimals); // Zero-terminator and "."
    memcpy(out,iStr,iStrLen);
    out[iStrLen]='.';
    memcpy(out+iStrLen+1,fStr,fStrLen);
    out[iStrLen+fStrLen+1]=0;
    free(fStr);
    free(iStr);
    return out;
}

char *text::doubleToStringWithFixedPrecision(double in, uint8_t precision)
{
    // Modify doubleToString, too.
    double i,f;
    f=modf(in,&i);
    bool negative=in<0.0;
    // This works both when i is negative and when f is negative (both can be negative).
    if(f<0.0)
        f*=-1.0;
    if(i<0.0)
        i*=-1.0;
    char *iStr=unsignedLongToString((uint64_t)i);
    if(precision==0)
        return iStr;
    char *fStr=unsignedLongToString(roundl((f*pow((double)10,precision+1))/10.0)); // Precision loss inavoidable.
    int iStrLen=strlen(iStr);
    int fStrLen=strlen(fStr);
    uint8_t emptyDecimals;
    if(f==0.0)
    {
        emptyDecimals=0;
        char *azStr=mkstr(precision);
        memset(azStr,'0',precision);
        free(fStr);
        fStr=azStr;
        fStrLen=precision;
    }
    else
    {
        emptyDecimals=(uint8_t)((double)(floor(log10((double)f))+1)*-1.0);
        if(emptyDecimals>0)
        {
            // Prepend empty decimals
            fStrLen+=emptyDecimals;
            bool appendZeros=fStrLen<precision;
            int zerosToAppend=precision-fStrLen;
            char *zeroString=mkstr(emptyDecimals);
            memset(zeroString,'0',emptyDecimals);
            char *nStr;
            if(appendZeros)
            {
                char *azStr=mkstr(zerosToAppend);
                memset(azStr,'0',zerosToAppend);
                nStr=concat(zeroString,fStr,azStr);
                free(azStr);
                fStrLen+=zerosToAppend;
            }
            else
                nStr=concat(zeroString,fStr);
            free(fStr);
            fStr=nStr;
            free(zeroString);
        }
        while(fStr[fStrLen-1]=='0'&&fStrLen>(precision>1?precision:1))
            fStrLen--;
    }
    if(negative)
    {
        char *out=(char*)malloc(iStrLen+fStrLen+3+emptyDecimals); // Zero-terminator, "-" and "."
        out[0]='-';
        memcpy(out+1,iStr,iStrLen);
        out[iStrLen+1]='.';
        memcpy(out+iStrLen+2,fStr,fStrLen);
        out[iStrLen+fStrLen+2]=0;
        free(fStr);
        free(iStr);
        return out;
    }
    char *out=(char*)malloc(iStrLen+fStrLen+2+emptyDecimals); // Zero-terminator and "."
    memcpy(out,iStr,iStrLen);
    out[iStrLen]='.';
    memcpy(out+iStrLen+1,fStr,fStrLen);
    out[iStrLen+fStrLen+1]=0;
    free(fStr);
    free(iStr);
    return out;
}

char *text::unsignedIntToString(uint32_t in)
{
    char *out=(char*)calloc(11,1); // 10+1
    uint32_t *temp=(uint32_t*)calloc(11,sizeof(uint32_t)); // Retrieve a single value for each position.
    temp[0]=in;
    for(uint8_t i=0;i<9;i++) // Amount of decimals in highest possible unsigned int - 1 (highest position will never be >9) (10-1).
    {
        uint32_t t=temp[i];
        uint32_t r=t%10;
        uint32_t n=(t-r)/10;
        temp[i+1]=n;
        temp[i]=r;
        if(n==0)
            break;
    }
    char reachedValueAt=-1;
    for(char i=9;i>=0;i--) // Amount of decimals in highest possible unsigned int - 1 (highest position will never be >9) (10-1).
    {
        uint32_t t=temp[(uint8_t)i];
        if(reachedValueAt==-1)
        {
            if(t==0)
                continue;
            reachedValueAt=i;
        }
        out[reachedValueAt-i]=(char)48+t; // 48: ASCII 0
    }
    free(temp);
    if(reachedValueAt==-1)
    {
        free(out);
        return duplicateString("0");
    }
    return out;
}

char *text::unsignedLongToString(uint64_t in)
{
    char *out=(char*)calloc(21,1); // Amount of decimals in highest possible unsigned long + zero-terminator (20+1)
    uint64_t *temp=(uint64_t*)calloc(sizeof(uint64_t)*20,sizeof(uint64_t)); // Retrieve a single value for each position.
    temp[0]=in;
    for(uint8_t i=0;i<19;i++) // Amount of decimals in highest possible unsigned long - 1 (highest position will never be >9) (20-1).
    {
        uint64_t t=temp[i];
        uint64_t r=t%10;
        uint64_t n=(t-r)/10;
        temp[i+1]=n;
        temp[i]=r;
        if(n==0)
            break;
    }
    char reachedValueAt=-1;
    for(char i=19;i>=0;i--) // Amount of decimals in highest possible unsigned long - 1 (highest position will never be >9) (20-1).
    {
        uint64_t t=temp[(uint8_t)i];
        if(reachedValueAt==-1)
        {
            if(t==0)
                continue;
            reachedValueAt=i;
        }
        out[reachedValueAt-i]=(char)(48+t); // 48: ASCII & UTF8 0
    }
    free(temp);
    if(reachedValueAt==-1)
    {
        free(out);
        return duplicateString("0");
    }
    return out;
}

int32_t text::intFromString(const char *in)
{
    int32_t out=0;
    int len=strlen(in);
    uint8_t n=in[0]=='-'?1:0;
    if(n||in[0]=='+')
    {
        in++;
        len--;
    }
    for(int i=0;i<len;i++)
        out+=(in[i]-48)*int32Pow(10,len-i-1); // 48: ASCII & UTF8 0
    return out*(n?-1:1);
}

int64_t text::longFromString(const char *in)
{
    int64_t out=0;
    int len=strlen(in);
    uint8_t n=in[0]=='-'?1:0;
    if(n||in[0]=='+')
    {
        in++;
        len--;
    }
    for(int i=0;i<len;i++)
    {
        out+=(in[i]-48)*int64Pow(10,len-i-1); // 48: ASCII & UTF8 0
    }
    return out*(n?-1:1);
}

char *text::byteToHexString(const char in, bool terminateString)
{
    const char *table="0123456789ABCDEF";
    char *out=(char*)malloc(2+(terminateString?1:0));
    out[0]=table[(in&0xF0)>>4];
    out[1]=table[in&0x0F];
    if(terminateString)
        out[2]=0;
    return out;
}

char *text::bytesToHexString(const char *in, size_t len, bool addSpaces)
{
    const char *table="0123456789ABCDEF";
    char *out=mkstr(len*2+(addSpaces?len-1:0));
    size_t pos=0;
    uint8_t thisChar;
    for(size_t i=0;i<len;i++)
    {
        thisChar=(uint8_t)in[i];
        if(addSpaces&&i>0)
            out[pos++]=' ';
        out[pos++]=table[(thisChar&0xF0)>>4];
        out[pos++]=table[thisChar&0x0F];
    }
    return out;
}

char *text::bytesFromHexString(const char *in, size_t &size)
{
    // Could contain spaces or other irrelevant chars. Use a buffer system.
    size_t len=strlen(in);
    size=0;
    char *out=(char*)malloc(len); // Larger than the max value.
    bool first=true;
    uint8_t next=0;
    char thisChar;
    for(size_t i=0;i<len;i++)
    {
        thisChar=in[i];
        if(thisChar=='0')
        {
            if(first)
            {
                next=0x0<<4;
                first=false;
                continue;
            }
            next|=0x0;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='1')
        {
            if(first)
            {
                next=0x1<<4;
                first=false;
                continue;
            }
            next|=0x1;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='2')
        {
            if(first)
            {
                next=0x2<<4;
                first=false;
                continue;
            }
            next|=0x2;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='3')
        {
            if(first)
            {
                next=0x3<<4;
                first=false;
                continue;
            }
            next|=0x3;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='4')
        {
            if(first)
            {
                next=0x4<<4;
                first=false;
                continue;
            }
            next|=0x4;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='5')
        {
            if(first)
            {
                next=0x5<<4;
                first=false;
                continue;
            }
            next|=0x5;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='6')
        {
            if(first)
            {
                next=0x6<<4;
                first=false;
                continue;
            }
            next|=0x6;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='7')
        {
            if(first)
            {
                next=0x7<<4;
                first=false;
                continue;
            }
            next|=0x7;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='8')
        {
            if(first)
            {
                next=0x8<<4;
                first=false;
                continue;
            }
            next|=0x8;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='9')
        {
            if(first)
            {
                next=0x9<<4;
                first=false;
                continue;
            }
            next|=0x9;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='A'||thisChar=='a')
        {
            if(first)
            {
                next=0xA<<4;
                first=false;
                continue;
            }
            next|=0xA;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='B'||thisChar=='b')
        {
            if(first)
            {
                next=0xB<<4;
                first=false;
                continue;
            }
            next|=0xB;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='C'||thisChar=='c')
        {
            if(first)
            {
                next=0xC<<4;
                first=false;
                continue;
            }
            next|=0xC;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='D'||thisChar=='d')
        {
            if(first)
            {
                next=0xD<<4;
                first=false;
                continue;
            }
            next|=0xD;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='E'||thisChar=='e')
        {
            if(first)
            {
                next=0xE<<4;
                first=false;
                continue;
            }
            next|=0xE;
            first=true;
            out[size++]=next;
        }
        else if(thisChar=='F'||thisChar=='f')
        {
            if(first)
            {
                next=0xF<<4;
                first=false;
                continue;
            }
            next|=0xF;
            first=true;
            out[size++]=next;
        }
    }
    if(!first) // Example: "1"
        out[size++]=in[len-1];
    return out;
}

int32_t text::round(double in)
{
    int32_t f=(int32_t)floor(in);
    return in<0.0?((double)in-f>0.5?f+1:f):((double)in-f>=0.5?f+1:f);
}

int32_t text::roundf(float in)
{
    int32_t f=(int32_t)floor(in);
    return in<0.0?((float)in-f>0.5f?f+1:f):((float)in-f>=0.5f?f+1:f);
}

int64_t text::roundl(double in)
{
    int64_t f=(int64_t)floorl(in);
    return in<0.0?((double)in-f>0.5?f+1:f):((double)in-f>=0.5?f+1:f);
}

double text::roundToPrecision(double in, int32_t precision)
{
    return round(in*pow((double)10,(double)precision))/pow((double)10,(double)precision);
}

double text::doubleFromString(const char *in)
{
    // Only supports a.b
    size_t dotPos=indexOf(in,".");
    if(dotPos==pos_notFound)
        return (double)longFromString(in);
    bool negative=in[0]=='-'; // Needed for cases like -0.5
    int64_t base=longFromString(substr(in,negative?1:0,dotPos-(negative?1:0)));
    char *fracStr=substr(in,dotPos+1);
    int64_t fraction=longFromString(fracStr);
    int8_t n=base<0?-1:1;
    double out=(double)base+((double)fraction/int64Pow(10,strlen(fracStr)))*n;
    free(fracStr);
    return out*(negative?-1.0:1.0);
}

size_t text::indexOf(const char *haystack, const char *needle)
{
    char *pos=strstr(const_cast<char*>(haystack),const_cast<char*>(needle));
    if(pos==0)
        return pos_notFound;
    size_t out=pos-haystack;
    return out;
}

size_t text::indexOfFrom(const char *haystack, const char *needle, size_t startFrom)
{
    char *pos=strstr(const_cast<char*>(haystack)+startFrom,const_cast<char*>(needle));
    if(pos==0)
        return pos_notFound;
    size_t out=pos-haystack;
    return out;
}

size_t text::lastIndexOf(const char *haystack, const char *needle)
{
    size_t haystackLen=strlen(haystack);
    size_t needleLen=strlen(needle);
    if(needleLen>haystackLen||haystackLen==0)
        return pos_notFound;
    for(size_t i=haystackLen-needleLen+1;i>0;i--) // Use this because text_t cannot be -1.
    {
        if(strncmp(haystack+i-1/*See above.*/,needle,needleLen)==0)
            return i-1;
    }
    return pos_notFound;
}

size_t text::lastIndexOfTo(const char *haystack, const char *needle, size_t to)
{
    size_t haystackLen=strlen(haystack);
    size_t needleLen=strlen(needle);
    if(needleLen>haystackLen||haystackLen==0)
        return pos_notFound;
    for(size_t i=to+1;i>0;i--) // Use this because text_t cannot be -1.
    {
        if(strncmp(haystack+i-1/*See above.*/,needle,needleLen)==0)
            return i-1;
    }
    return pos_notFound;
}

size_t text::indexOf(const char *haystack, char needle)
{
    size_t l=strlen(haystack);
    for(size_t i=0;i<l;i++)
    {
        char chr=haystack[i];
        if(chr==needle)
            return i;
    }
    return pos_notFound;
}

size_t text::indexOfFrom(const char *haystack, char needle, size_t startFrom)
{
    size_t l=strlen(haystack);
    for(size_t i=startFrom;i<l;i++)
    {
        char chr=haystack[i];
        if(chr==needle)
            return i;
    }
    return pos_notFound;
}

size_t text::lastIndexOf(const char *haystack, char needle)
{
    size_t l=strlen(haystack);
    if(l==0)
        return pos_notFound;
    for(size_t i=l;i>0;i--) // size_t cannot be negative, thus the value of "i" is real index + 1.
    {
        char chr=haystack[i-1]; // See comment above.
        if(chr==needle)
            return i-1;
    }
    return pos_notFound;
}

size_t text::lastIndexOfTo(const char *haystack, char needle, size_t to)
{
    size_t l=strlen(haystack);
    if(l==0)
        return pos_notFound;
    for(size_t i=to+1;i>0;i--) // size_t cannot be negative, thus the value of "i" is real index + 1.
    {
        char chr=haystack[i-1]; // See comment above.
        if(chr==needle)
            return i-1;
    }
    return pos_notFound;
}

size_t text::indexOf(const std::vector<std::string> *haystack, std::string needle)
{
    size_t haystackLen=haystack->size();
    for(size_t i=0;i<haystackLen;i++)
    {
        if(haystack->at(i)==needle)
            return i;
    }
    return pos_notFound;
}

size_t text::indexOfFrom(const std::vector<std::string> *haystack, std::string needle, size_t startFrom)
{
    size_t haystackLen=haystack->size();
    for(size_t i=startFrom;i<haystackLen;i++)
    {
        if(haystack->at(i)==needle)
            return i;
    }
    return pos_notFound;
}

size_t text::lastIndexOf(const std::vector<std::string> *haystack, std::string needle)
{
    size_t haystackLen=haystack->size();
    for(size_t i=haystackLen;i>0;i--) // Use this because text_t cannot be -1.
    {
        if(haystack->at(i-1/*See above.*/)==needle)
            return i;
    }
    return pos_notFound;
}

size_t text::lastIndexOfTo(const std::vector<std::string> *haystack, std::string needle, size_t to)
{
    for(size_t i=to+1;i>0;i--) // Use this because text_t cannot be -1.
    {
        if(haystack->at(i-1/*See above.*/)==needle)
            return i;
    }
    return pos_notFound;
}

char *text::substr(const char *str, size_t start)
{
    return substr(str,start,strlen(str)-start);
}

char *text::substr(const char *str, size_t start, size_t length)
{
    char *out=mkstr(length);
    memcpy(out,str+start,length);
    return out;
}

char *text::freeAndReturn(char *toFree, char *out)
{
    free(toFree);
    return out;
}

const char *text::freeAndReturn(char *toFree, const char *out)
{
    free(toFree);
    return out;
}

std::string text::toStringAndFree(char *str)
{
    std::string out=std::string(str);
    free(str);
    return out;
}

char *text::replace(const char *str, const char *what, const char *with)
{
    size_t i=0;
    size_t whatLen=strlen(what);
    size_t withLen=strlen(with);
    size_t len=strlen(str);
    // We need "in" to avoid modifying an immutable string.
    char *in=duplicateString(str);
Next:
    size_t n=indexOfFrom(in,what,i);
    if(n!=pos_notFound)
    {
        len=strlen(in);
        char *newStr=(char*)mkstr(len-whatLen+withLen);
        memcpy(newStr,in,n);
        memcpy(newStr+n,with,withLen);
        memcpy(newStr+n+withLen,in+n+whatLen,len-n-whatLen);
        free(in);
        in=newStr;
        i=n+withLen+1;
        if(i==strlen(in))
            goto Ret;
        goto Next;
    }
Ret:
    return in;
}

char *text::escape(const char *str)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length*2); // Max possible size
    char thisChar;
    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='\'')
        {
            out[outPos++]='\\';
            out[outPos++]='\'';
            continue;
        }
        else if(thisChar=='"')
        {
            out[outPos++]='\\';
            out[outPos++]='"';
            continue;
        }
        else if(thisChar=='\\')
        {
            out[outPos++]='\\';
            out[outPos++]='\\';
            continue;
        }
        out[outPos++]=thisChar;
    }
    out[outPos]=0; // Terminate the string.
    return out;
}

char *text::unescape(const char *str)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length); // Max possible size.
    char thisChar;
    char prevChar=0;

    #define TEXT_UNESCAPE_NEXT_ITERATION \
    \
    prevChar=thisChar;\
    continue;

    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='\'')
        {
            if(prevChar=='\\')
            {
                out[outPos-1]=thisChar; // No ++ here.
                TEXT_UNESCAPE_NEXT_ITERATION;
            }
        }
        else if(thisChar=='"')
        {
            if(prevChar=='\\')
            {
                out[outPos-1]=thisChar; // No ++ here.
                TEXT_UNESCAPE_NEXT_ITERATION;
            }
        }
        else if(thisChar=='\\')
        {
            if(prevChar=='\\')
            {
                prevChar=0;
                continue; // Not TEXT_UNESCAPE_NEXT_ITERATION, we want to avoid errors if: \\"
            }
        }
        out[outPos++]=thisChar;
        TEXT_UNESCAPE_NEXT_ITERATION;
    }

    out[outPos]=0; // Terminate the string.

    #undef TEXT_UNESCAPE_NEXT_ITERATION

    return out;
}

char *text::escapeDoubleQuotationMarks(const char *str)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length*2); // Max possible size
    char thisChar;
    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='"')
        {
            out[outPos++]='\\';
            out[outPos++]='"';
            continue;
        }
        else if(thisChar=='\\')
        {
            out[outPos++]='\\';
            out[outPos++]='\\';
            continue;
        }
        out[outPos++]=thisChar;
    }
    out[outPos]=0; // Terminate the string.
    return out;
}

char *text::unescapeDoubleQuotationMarks(const char *str)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length); // Max possible size.
    char thisChar;
    char prevChar=0;

    #define TEXT_UNESCAPE_NEXT_ITERATION \
    \
    prevChar=thisChar;\
    continue;

    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='"')
        {
            if(prevChar=='\\')
            {
                out[outPos-1]=thisChar; // No ++ here.
                TEXT_UNESCAPE_NEXT_ITERATION;
            }
        }
        else if(thisChar=='\\')
        {
            if(prevChar=='\\')
            {
                prevChar=0;
                continue; // Not TEXT_UNESCAPE_NEXT_ITERATION, we want to avoid errors if: \\"
            }
        }
        out[outPos++]=thisChar;
        TEXT_UNESCAPE_NEXT_ITERATION;
    }

    out[outPos]=0; // Terminate the string.

    #undef TEXT_UNESCAPE_NEXT_ITERATION

    return out;
}

char *text::unescapeDoubleQuotationMarksUntilEnd(const char *str, bool excludeFirst)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length); // Max possible size.
    char thisChar;
    char prevChar=0;
    bool nonWhitespacePassed=false;

    #define TEXT_UNESCAPE_NEXT_ITERATION \
    \
    prevChar=thisChar;\
    continue;

    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='"')
        {
            if(prevChar=='\\')
            {
                out[outPos-1]=thisChar; // No ++ here.
                TEXT_UNESCAPE_NEXT_ITERATION;
            }
            // Reached valid closing "
            if(!nonWhitespacePassed&&excludeFirst)
                continue;
            out[outPos]=0;
            return out;
        }
        else if(thisChar=='\\')
        {
            if(prevChar=='\\')
            {
                prevChar=0;
                continue; // Not TEXT_UNESCAPE_NEXT_ITERATION, we want to avoid errors if: \\"
            }
        }
        if(!nonWhitespacePassed&&!isWhitespace(thisChar))
            nonWhitespacePassed=true;

        out[outPos++]=thisChar;
        TEXT_UNESCAPE_NEXT_ITERATION;
    }

    out[outPos]=0; // Terminate the string.

    #undef TEXT_UNESCAPE_NEXT_ITERATION

    return out;
}

char *text::escapeSingleQuotationMarks(const char *str)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length*2); // Max possible size
    char thisChar;
    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='\'')
        {
            out[outPos++]='\\';
            out[outPos++]='\'';
            continue;
        }
        else if(thisChar=='\\')
        {
            out[outPos++]='\\';
            out[outPos++]='\\';
            continue;
        }
        out[outPos++]=thisChar;
    }
    out[outPos]=0; // Terminate the string.
    return out;

}

char *text::unescapeSingleQuotationMarks(const char *str)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length); // Max possible size.
    char thisChar;
    char prevChar=0;

    #define TEXT_UNESCAPE_NEXT_ITERATION \
    \
    prevChar=thisChar;\
    continue;

    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='\'')
        {
            if(prevChar=='\\')
            {
                out[outPos-1]=thisChar; // No ++ here.
                TEXT_UNESCAPE_NEXT_ITERATION;
            }
        }
        else if(thisChar=='\\')
        {
            if(prevChar=='\\')
            {
                prevChar=0;
                continue; // Not TEXT_UNESCAPE_NEXT_ITERATION, we want to avoid errors if: \\'
            }
        }
        out[outPos++]=thisChar;
        TEXT_UNESCAPE_NEXT_ITERATION;
    }

    out[outPos]=0; // Terminate the string.

    #undef TEXT_UNESCAPE_NEXT_ITERATION

    return out;
}

char *text::unescapeSingleQuotationMarksUntilEnd(const char *str, bool excludeFirst)
{
    size_t length=strlen(str);
    size_t outPos=0;
    char *out=(char*)mkstr(length); // Max possible size.
    char thisChar;
    char prevChar=0;
    bool nonWhitespacePassed=false;

    #define TEXT_UNESCAPE_NEXT_ITERATION \
    \
    prevChar=thisChar;\
    continue;

    for(size_t i=0;i<length;i++)
    {
        thisChar=str[i];
        if(thisChar=='\'')
        {
            if(prevChar=='\\')
            {
                out[outPos-1]=thisChar; // No ++ here.
                TEXT_UNESCAPE_NEXT_ITERATION;
            }
            // Reached valid closing '
            if(!nonWhitespacePassed&&excludeFirst)
                continue;
            out[outPos]=0;
            return out;
        }
        else if(thisChar=='\\')
        {
            if(prevChar=='\\')
            {
                prevChar=0;
                continue; // Not TEXT_UNESCAPE_NEXT_ITERATION, we want to avoid errors if: \\'
            }
        }
        if(!nonWhitespacePassed&&!isWhitespace(thisChar))
            nonWhitespacePassed=true;

        out[outPos++]=thisChar;
        TEXT_UNESCAPE_NEXT_ITERATION;
    }

    out[outPos]=0; // Terminate the string.

    #undef TEXT_UNESCAPE_NEXT_ITERATION

    return out;
}

std::vector<char *> text::split(const char *in, const char *separator)
{
    std::vector<char*> out;
    size_t separatorLen=strlen(separator);
    size_t len=strlen(in);
    if(len==0)
        return std::vector<char*>();
    char *from=duplicateString(in);
    char *next;
    char *last=0;
    while((next=strstr(from,separator))!=0)
    {
        out.push_back(substr(from,0,next-from)); // Text before separator
        from=next+separatorLen;
        if(from[0]==0)
        {
            // Reached end of string.
            return out;
        }
        last=from;
    }
    if(last!=0) // Push last item. If we reach this, it means there is still an item at the end.
        out.push_back(duplicateString(last));
    else if(out.size()==0)
        out.push_back(duplicateString(in));
    return out;
}

std::vector<std::string> text::splitToStringArray(const char *in, const char *separator)
{
    std::vector<std::string> out;
    size_t separatorLen=strlen(separator);
    size_t len=strlen(in);
    if(len==0)
        return std::vector<std::string>();
    char *from=duplicateString(in);
    char *next;
    char *last=0;
    while((next=strstr(from,separator))!=0)
    {
        out.push_back(toStringAndFree(substr(from,0,next-from))); // Text before separator
        from=next+separatorLen;
        if(from[0]==0)
        {
            // Reached end of string.
            return out;
        }
        last=from;
    }
    if(last!=0) // Push last item. If we reach this, it means there is still an item at the end.
        out.push_back(std::string(last));
    else if(out.size()==0)
        out.push_back(std::string(in));
    return out;
}

size_t text::count(const char *haystack, const char *needle)
{
    size_t out=0;
    size_t needleLen=strlen(needle);
    char *from=duplicateString(haystack);
    char *next;
    while((next=strstr(from,needle))!=0)
    {
        out++;
        from=next+needleLen;
        if(from[0]==0)
            return out;
    }
    return out; // This is never reached.
}

size_t text::count(const char *haystack, char needle)
{
    size_t out=0;
    size_t len=strlen(haystack);
    for(size_t i=0;i<len;i++)
    {
        if(haystack[i]==needle)
            out++;
    }
    return out;
}

size_t text::countUnique(const char *haystack)
{
    std::string found;
    size_t count=0;
    size_t len=strlen(haystack);
    for(size_t i=0;i<len;i++)
    {
        char thisChar=haystack[i];
        if(found.find(thisChar)==std::string::npos)
        {
           count++;
           found.append(1,thisChar);
        }
    }
    return count;
}

size_t text::countUnique(std::vector<std::string> haystack)
{
    size_t count=0;
    std::vector<std::string> found;
    for(size_t i=0;i<haystack.size();i++)
    {
        std::string thisStr=haystack.at(i);
        if(indexOf(&found,thisStr)==pos_notFound)
        {
            count++;
            found.push_back(thisStr);
        }
    }
    return count;
}

char *text::trimStart(const char *str)
{
    size_t trimStart=0;
    size_t inLen=strlen(str);
    while(trimStart<inLen&&isWhitespace(str[trimStart])) // (char)0 is not a whitespace char.
        trimStart++;
    if(trimStart==inLen)
        return duplicateString("");
    return substr(str,trimStart);
}

char *text::trimEnd(const char *str)
{
    size_t trimEnd=0;
    size_t inLen=strlen(str);
    while(trimEnd<inLen&&isWhitespace(str[inLen-trimEnd-1])) // (char)0 is not a whitespace char.
        trimEnd++;
    if(trimEnd==inLen)
        return duplicateString("");
    return substr(str,0,inLen-trimEnd);
}

char *text::trim(const char *str)
{
    size_t trimStart=0;
    size_t trimEnd=0;
    size_t inLen=strlen(str);
    if(inLen==0)
        return duplicateString(str);
    while(trimStart<inLen&&isWhitespace(str[trimStart])) // (char)0 is not a whitespace char.
        trimStart++;
    while(trimEnd<inLen&&isWhitespace(str[inLen-trimEnd-1])) // (char)0 is not a whitespace char.
        trimEnd++;
    if(trimStart==inLen)
        return duplicateString("");
    return substr(str,trimStart,inLen-trimStart-trimEnd);
}

char *text::firstChars(const char *in, size_t chars)
{
    char *out=(char*)mkstr(chars);
    memcpy(out,in,chars);
    return out;
}

char *text::lastChars(const char *in, size_t chars)
{
    char *out=(char*)mkstr(chars);
    size_t len=strlen(in);
    memcpy(out,in+len-chars,chars);
    return out;
}

std::string text::trimStart(std::string str)
{
    size_t trimStart=0;
    size_t inLen=str.length();
    while(trimStart<inLen&&isWhitespace(str[trimStart])) // (char)0 is not a whitespace char.
        trimStart++;
    if(trimStart==str.length())
        return std::string("");
    return str.substr(trimStart);
}

std::string text::trimEnd(std::string str)
{
    size_t trimEnd=0;
    size_t inLen=str.length();
    while(trimEnd<inLen&&isWhitespace(str[inLen-trimEnd-1])) // (char)0 is not a whitespace char.
        trimEnd++;
    if(trimEnd==inLen)
        return std::string("");
    return str.substr(0,inLen-trimEnd);
}

std::string text::trim(std::string str)
{
    size_t trimStart=0;
    size_t trimEnd=0;
    size_t inLen=str.length();
    if(inLen==0)
        return std::string("");
    while(trimStart<inLen&&isWhitespace(str[trimStart])) // (char)0 is not a whitespace char.
        trimStart++;
    while(trimEnd<inLen&&isWhitespace(str[inLen-trimEnd-1])) // (char)0 is not a whitespace char.
        trimEnd++;
    if(trimStart==inLen)
        return std::string("");
    return str.substr(trimStart,inLen-trimStart-trimEnd);
}

std::string text::firstChars(std::string in, size_t chars)
{
    return in.substr(0,chars);
}

std::string text::lastChars(std::string in, size_t chars)
{
    return in.substr(in.length()-chars);
}

wchar_t *text::wFirstChars(const wchar_t *in, size_t chars)
{
    wchar_t *out=mkwstr(chars);
    memcpy(out,in,chars*sizeof(wchar_t));
    return out;
}

wchar_t *text::wLastChars(const wchar_t *in, size_t chars)
{
    wchar_t *out=mkwstr(chars);
    size_t len=wcslen(in);
    memcpy(out,in+len-chars,chars*sizeof(wchar_t));
    return out;
}

bool text::isWhitespace(char chr)
{
    return chr==' '  ||
           chr=='\t' ||
           chr=='\r' ||
           chr=='\n'
            ;
}

char *text::strToUpper(const char *str)
{
    size_t len=strlen(str);
    char *out=(char*)malloc(len+1);
    out[len]=0;
    for(size_t i=0;i<len;i++)
        out[i]=toupper(str[i]);
    return out;
}

char *text::strToLower(const char *str)
{
    size_t len=strlen(str);
    char *out=(char*)malloc(len+1);
    out[len]=0;
    for(size_t i=0;i<len;i++)
        out[i]=tolower(str[i]);
    return out;
}

std::string text::strToUpper(std::string str)
{
    size_t len=str.length();
    std::string out=std::string(len,0);
    for(size_t i=0;i<len;i++)
        out.at(i)=toupper(str.at(i));
    return out;
}

std::string text::strToLower(std::string str)
{
    size_t len=str.length();
    std::string out=std::string(len,0);
    for(size_t i=0;i<len;i++)
        out.at(i)=tolower(str.at(i));
    return out;
}

bool text::iCompare(std::string strA, std::string strB)
{
    return strToLower(strA)==strToLower(strB);
}

bool text::iCompare(const char *strA, const char *strB)
{
    size_t aLen=strlen(strA);
    size_t bLen=strlen(strB);
    if(aLen!=bLen)
        return false;
    for(size_t i=0;i<aLen;i++)
    {
        char aChar=strA[i];
        char bChar=strB[i];
        if(tolower(aChar)!=tolower(bChar))
            return false;
    }
    return true;
}

bool text::startsWith(const char *str, const char *with)
{
    size_t strLen=strlen(str);
    size_t withLen=strlen(with);
    if(withLen>strLen||withLen==0)
        return false;
    char *cmp=substr(str,0,withLen);
    bool out=strcmp(cmp,with)==0;
    free(cmp);
    return out;
}

bool text::endsWith(const char *str, const char *with)
{
    size_t strLen=strlen(str);
    size_t withLen=strlen(with);
    if(withLen>strLen||withLen==0)
        return false;
    char *cmp=substr(str,strLen-withLen);
    bool out=strcmp(cmp,with)==0;
    free(cmp);
    return out;
}

bool text::iStartsWith(const char *str, const char *with)
{
    size_t strLen=strlen(str);
    size_t withLen=strlen(with);
    if(withLen>strLen||withLen==0)
        return false;
    char *cmp=substr(str,0,withLen);
    bool out=iCompare(cmp,with);
    free(cmp);
    return out;
}

bool text::iEndsWith(const char *str, const char *with)
{
    size_t strLen=strlen(str);
    size_t withLen=strlen(with);
    if(withLen>strLen||withLen==0)
        return false;
    char *cmp=substr(str,strLen-withLen);
    bool out=iCompare(cmp,with);
    free(cmp);
    return out;
}

bool text::startsWith(std::string str, std::string with)
{
    size_t strLen=str.length();
    size_t withLen=with.length();
    if(withLen>strLen||withLen==0)
        return false;
    return str.substr(0,withLen)==with;
}

bool text::endsWith(std::string str, std::string with)
{
    size_t strLen=str.length();
    size_t withLen=with.length();
    if(withLen>strLen||withLen==0)
        return false;
    return str.substr(strLen-withLen)==with;
}

bool text::iStartsWith(std::string str, std::string with)
{
    size_t strLen=str.length();
    size_t withLen=with.length();
    if(withLen>strLen||withLen==0)
        return false;
    return iCompare(str.substr(0,withLen),with);
}

bool text::iEndsWith(std::string str, std::string with)
{
    size_t strLen=str.length();
    size_t withLen=with.length();
    if(withLen>strLen||withLen==0)
        return false;
    return iCompare(str.substr(strLen-withLen),with);
}

char *text::charToString(char in)
{
    char *out=mkstr(1);
    out[0]=in;
    return out;
}

char *text::getDirPath(const char *path)
{
    char *nPath=duplicateString(path);
    if(indexOf(nPath,"/")!=pos_notFound)
    {
        char *nnPath=replace(nPath,"/","\\");
        free(nPath);
        nPath=nnPath;
    }
    size_t len=strlen(nPath);
    if(nPath[len-1]=='\\')
    {
        if(len==1)
            return duplicateString(nPath);
        len--;
    }
    size_t pos=lastIndexOfTo(nPath,"\\",len-1);
    if(pos==pos_notFound)
        return duplicateString(nPath);
    return freeAndReturn(nPath,substr(nPath,0,pos+1));
}

char *text::getFileName(const char *filePath)
{
    char *nFilePath=duplicateString(filePath);
    if(indexOf(nFilePath,"/")!=pos_notFound)
    {
        char *nnFilePath=replace(nFilePath,"/","\\");
        free(nFilePath);
        nFilePath=nnFilePath;
    }
    size_t pos=lastIndexOf(nFilePath,"\\");
    return freeAndReturn(nFilePath,substr(nFilePath,pos+1,strlen(nFilePath)-pos-1));
}

char *text::getFileExtension(const char *filePath)
{
    char *nFilePath=duplicateString(filePath);
    if(indexOf(nFilePath,"/")!=pos_notFound)
    {
        char *nnFilePath=replace(nFilePath,"/","\\");
        free(nFilePath);
        nFilePath=nnFilePath;
    }
    size_t pos=lastIndexOf(nFilePath,".");
    if(pos==pos_notFound)
        return freeAndReturn(nFilePath,duplicateString(""));
    return freeAndReturn(nFilePath,substr(nFilePath,pos+1,strlen(nFilePath)-pos-1));
}

char *text::getFileNameWithoutExtension(const char *filePath)
{
    char *nFilePath=duplicateString(filePath);
    if(indexOf(nFilePath,"/")!=pos_notFound)
    {
        char *nnFilePath=replace(nFilePath,"/","\\");
        free(nFilePath);
        nFilePath=nnFilePath;
    }
    size_t pos=lastIndexOf(nFilePath,"\\");
    size_t pos2=lastIndexOf(nFilePath,".");
    if(pos2==pos_notFound)
    {
        if(pos==pos_notFound)
            return nFilePath;
        return substr(nFilePath,pos+1,strlen(nFilePath)-pos-1);
    }
    if(pos==pos_notFound)
        return substr(nFilePath,0,pos2);
    return substr(nFilePath,pos+1,pos2-pos-1);
}

std::vector<char *> text::stringVectorToCharPtrVector(std::vector<std::string> in)
{
   std::vector<char *> out=std::vector<char *>();
   size_t size=in.size();
   for(size_t i=0;i<size;i++)
       out.push_back(duplicateString(in.at(i).c_str()));
   return out;
}

std::vector<std::string> text::charPtrVectorToStringVector(std::vector<char *> in, bool freeCharPtrs)
{
    std::vector<std::string> out=std::vector<std::string>();
    size_t size=in.size();
    if(freeCharPtrs)
    {
        for(size_t i=0;i<size;i++)
        {
            char *ptr=in.at(i);
            out.push_back(std::string(ptr));
            free(ptr);
        }
    }
    else
    {
        for(size_t i=0;i<size;i++)
            out.push_back(std::string(in.at(i)));
    }
    return out;
}

void text::removeEmptyEntries(std::vector<std::string> *in, bool removeWhitespaceOnlyEntries)
{
    if(removeWhitespaceOnlyEntries)
    {
        size_t pos=0;
        while(pos<in->size())
        {
            if(trim(in->at(pos)).length()==0)
                in->erase(in->begin()+pos);
            else
                pos++;
        }
    }
    else
    {
        size_t pos=0;
        while(pos<in->size())
        {
            if(in->at(pos).length()==0)
                in->erase(in->begin()+pos);
            else
                pos++;
        }
    }
}

bool text::matchWildcard(const char *str, const char *pattern, bool ignoreCase, bool allowBackslashEscape, char anyCharsSymbol, char anyCharSymbol)
{
    if(ignoreCase)
    {
        str=strToLower(str);
        pattern=strToLower(pattern);
    }
    // Split pattern into parts
    std::vector<std::string> parts;
    size_t strLength=strlen(str);
    size_t patternLength=strlen(pattern);
    bool nextEscape=false;
    std::string nextStr=std::string("T");
    for(size_t i=0;i<patternLength;i++)
    {
        char chr=pattern[i];
        if(nextEscape)
        {
            nextStr+=chr;
            nextEscape=false;
            continue;
        }
        if(chr=='\\'&&allowBackslashEscape)
        {
            nextEscape=true;
            continue;
        }
        if(chr==anyCharsSymbol)
        {
            if(nextStr.length()>1) // All text parts start with "T"
            {
                parts.push_back(std::string(nextStr));
                nextStr=std::string("T"); // Text
            }
            parts.push_back("*");
        }
        else if(chr==anyCharSymbol)
        {
            if(nextStr.length()>1) // All text parts start with "T"
            {
                parts.push_back(std::string(nextStr));
                nextStr=std::string("T"); // Text
            }
            parts.push_back("?");
        }
        else
            nextStr+=chr;
    }
    if(nextStr.length()>1) // All text parts start with "T"
        parts.push_back(std::string(nextStr));

    // Now that we have the parts, match them against the string

    bool result=true;
    std::string nStr=std::string(str);
    size_t remainingLength=strLength;
    size_t startPos=0;
    size_t partCount=parts.size();
    for(size_t i=0;i<partCount;i++)
    {
        std::string part=parts.at(i);
        size_t partLength=part.length()-1;
        bool isText=part[0]=='T';
        bool isAnyChars=part[0]=='*';
        bool isAnyChar=part[0]=='?';

        if(isText)
        {
            if(partLength>remainingLength)
            {
                result=false;
                goto Ret;
            }
            if(nStr.substr(startPos,partLength).compare(part.substr(1))!=0)
            {
                result=false;
                goto Ret;
            }
            remainingLength-=partLength;
            startPos+=partLength;
        }
        else if(isAnyChar)
        {
            // Exactly one character
            if(remainingLength==0)
            {
                result=false;
                goto Ret;
            }
            remainingLength--;
            startPos++;
        }
        else if(isAnyChars)
        {
            // 0-n characters
            // Strategy: try to find the next part that has a definite meaning
            if(i==partCount-1) // If this is the last part of the pattern
                goto Ret;

            std::string nextPart;
            size_t nextPartLength;
            i++;
            for(;i<partCount;i++)
            {
                nextPart=parts.at(i);
                nextPartLength=nextPart.length()-1;
                if(nextPart[0]=='*') // **, ***, etc. are all equivalent to *
                {
                    if(i==partCount-1)
                        goto Ret;
                    continue;
                }
                else if(nextPart[0]=='?')
                {
                    if(remainingLength==0)
                    {
                        result=false;
                        goto Ret;
                    }
                    remainingLength--;
                    startPos++;
                }
                else // if(nextPart[0]=='T')
                {
                    if(nextPartLength>remainingLength)
                    {
                        result=false;
                        goto Ret;
                    }
                    // Try to find text
                    nextPart=nextPart.substr(1); // Remove "T" from beginning
                    bool foundMatch=false;
                    for(size_t offset=0;nextPartLength+offset<=remainingLength;offset++)
                    {
                        if(nStr.substr(startPos+offset,nextPartLength).compare(nextPart/*String trimmed above*/)==0)
                        {
                            startPos+=offset+nextPartLength;
                            remainingLength-=offset+nextPartLength;
                            foundMatch=true;
                            break;
                        }
                    }
                    if(foundMatch)
                        break;
                    result=false;
                    goto Ret;
                }
            }
        }
    }
    if(remainingLength>0)
        result=false;
    Ret:
    if(ignoreCase)
    {
        free(const_cast<char*>(str));
        free(const_cast<char*>(pattern));
    }
    return result;
}

void text::freeCharArrayVectorContents(std::vector<char *> vector)
{
    size_t size=vector.size();
    for(size_t i=0;i<size;i++)
        free(vector.at(i));
}
