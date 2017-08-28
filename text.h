#ifndef TEXT_H
#define TEXT_H

#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <limits>

#define pos_notFound (std::numeric_limits<size_t>::max())

typedef size_t text_t;

class text
{
public:
    static int32_t int32Pow(int32_t base,int32_t exp);
    static int64_t int64Pow(int64_t base,int64_t exp);
    static uint32_t uint32Pow(uint32_t base,uint32_t exp);
    static uint64_t uint64Pow(uint64_t base,uint64_t exp);
    static char *mkstr(size_t length);
    static wchar_t *mkwstr(size_t length);
    static char *duplicateString(const char *in);
    static char *terminateFixedLengthString(const char *in,size_t length);
    static char *concat(const char *part1,const char *part2);
    static char *concat(const char *part1,const char *part2,const char *part3);
    static char *concat(const char *part1,const char *part2,const char *part3,const char *part4);
    static char *concat(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5);
    static char *concat(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5,const char *part6);
    static char *concat(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5,const char *part6,const char *part7);
    static char *concat(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5,const char *part6,const char *part7,const char *part8);
    static wchar_t *concatWideString(const wchar_t *part1,const wchar_t *part2);
    static wchar_t *concatWideString(const wchar_t *part1,const wchar_t *part2,const wchar_t *part3);
    static wchar_t *concatWideString(const wchar_t *part1,const wchar_t *part2,const wchar_t *part3,const wchar_t *part4);
    static char *concatPaths(const char *part1,const char *part2);
    static char *concatPaths(const char *part1,const char *part2,const char *part3);
    static char *concatPaths(const char *part1,const char *part2,const char *part3,const char *part4);
    static char *concatPaths(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5);
    static char *concatPaths(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5,const char *part6);
    static char *concatPaths(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5,const char *part6,const char *part7);
    static char *concatPaths(const char *part1,const char *part2,const char *part3,const char *part4,const char *part5,const char *part6,const char *part7,const char *part8);
    static char *toString(int32_t in);
    static char *toString(int64_t in);
    static char *toString(uint32_t in);
    static char *toString(uint64_t in);
    static char *toString(double in);
    static char *toString(double in,uint8_t precision);
    static char *intToString(int32_t in);
    static char *longToString(int64_t in);
    static char *doubleToString(double in); // Warning: precision loss (inavoidable)
    static char *doubleToStringWithFixedPrecision(double in,uint8_t precision); // Warning: precision loss (inavoidable)
    static char *unsignedIntToString(uint32_t in);
    static char *unsignedLongToString(uint64_t in);
    static int32_t intFromString(const char *in);
    static int64_t longFromString(const char *in);
    static char *byteToHexString(const char in,bool terminateString);
    static char *bytesToHexString(const char *in,size_t len,bool addSpaces);
    static char *bytesFromHexString(const char *in,size_t &size);
    static int32_t round(double in);
    static int32_t roundf(float in);
    static int64_t roundl(double in);
    static double roundToPrecision(double in,int32_t precision);
    static double doubleFromString(const char *in); // Only supports a.b
    static size_t indexOf(const char *haystack,const char *needle);
    static size_t indexOfFrom(const char *haystack,const char *needle,size_t startFrom);
    static size_t lastIndexOf(const char *haystack,const char *needle);
    static size_t lastIndexOfTo(const char *haystack,const char *needle,size_t to); // "to" may not be bigger than strlen(haystack).
    static size_t indexOf(const char *haystack,char needle);
    static size_t indexOfFrom(const char *haystack,char needle,size_t startFrom);
    static size_t lastIndexOf(const char *haystack,char needle);
    static size_t lastIndexOfTo(const char *haystack,char needle,size_t to); // "to" may not be bigger than strlen(haystack).
    static size_t indexOf(const std::vector<std::string> *haystack,std::string needle);
    static size_t indexOfFrom(const std::vector<std::string> *haystack,std::string needle,size_t startFrom);
    static size_t lastIndexOf(const std::vector<std::string> *haystack,std::string needle);
    static size_t lastIndexOfTo(const std::vector<std::string> *haystack,std::string needle,size_t to); // "to" may not be bigger than haystack->length().
    static char *substr(const char *str,size_t start);
    static char *substr(const char *str,size_t start,size_t length);
    static char *freeAndReturn(char *toFree,char *out);
    static const char *freeAndReturn(char *toFree,const char *out);
    static std::string toStringAndFree(char *str);
    static char *replace(const char *str,const char *what,const char *with);
    static char *escape(const char *str); // Escapes all instances of \ " '
    static char *unescape(const char *str); // Unescapes all instances of \ " '
    static char *escapeDoubleQuotationMarks(const char *str); // Escapes all instances of \ "
    static char *unescapeDoubleQuotationMarks(const char *str); // Unescapes all instances of \ "
    static char *unescapeDoubleQuotationMarksUntilEnd(const char *str,bool excludeFirst=true); // Unescapes all instances of \ " until a valid closing " is met
    static char *escapeSingleQuotationMarks(const char *str); // Escapes all instances of \ '
    static char *unescapeSingleQuotationMarks(const char *str); // Unescapes all instances of \ '
    static char *unescapeSingleQuotationMarksUntilEnd(const char *str,bool excludeFirst=true); // Unescapes all instances of \ ' until a valid closing ' is met
    static std::vector<char*> split(const char *in,const char *separator);
    static std::vector<std::string> splitToStringArray(const char *in,const char *separator);
    static void freeCharArrayVectorContents(std::vector<char*> vector);
    static size_t count(const char *haystack,const char *needle);
    static size_t count(const char *haystack,char needle);
    static size_t countUnique(const char *haystack);
    static size_t countUnique(std::vector<std::string> haystack);
    static char *trimStart(const char *str);
    static char *trimEnd(const char *str);
    static char *trim(const char *str);
    static char *firstChars(const char *in,size_t chars);
    static char *lastChars(const char *in,size_t chars);
    static std::string trimStart(std::string str);
    static std::string trimEnd(std::string str);
    static std::string trim(std::string str);
    static std::string firstChars(std::string in,size_t chars);
    static std::string lastChars(std::string in,size_t chars);
    static wchar_t *wFirstChars(const wchar_t *in,size_t chars);
    static wchar_t *wLastChars(const wchar_t *in,size_t chars);
    static bool isWhitespace(char chr);
    static char *strToUpper(const char *str);
    static char *strToLower(const char *str);
    static std::string strToUpper(std::string str);
    static std::string strToLower(std::string str);
    static bool iCompare(std::string strA,std::string strB);
    static bool iCompare(const char *strA,const char *strB);
    static bool startsWith(const char *str,const char *with);
    static bool endsWith(const char *str,const char *with);
    static bool iStartsWith(const char *str,const char *with);
    static bool iEndsWith(const char *str,const char *with);
    static bool startsWith(std::string str,std::string with);
    static bool endsWith(std::string str,std::string with);
    static bool iStartsWith(std::string str,std::string with);
    static bool iEndsWith(std::string str,std::string with);
    static char *charToString(char in);
    static char *getDirPath(const char *path);
    static char *getFileName(const char *filePath);
    static char *getFileExtension(const char *filePath);
    static char *getFileNameWithoutExtension(const char *filePath);
    static std::vector<char*> stringVectorToCharPtrVector(std::vector<std::string> in);
    static std::vector<std::string> charPtrVectorToStringVector(std::vector<char*> in,bool freeCharPtrs);
    static void removeEmptyEntries(std::vector<std::string> *in,bool removeWhitespaceOnlyEntries=false);
    static bool matchWildcard(const char *str,const char *pattern,bool ignoreCase=true,bool allowBackslashEscape=true,char anyCharsSymbol='*',char anyCharSymbol='?');
};

#endif // TEXT_H
