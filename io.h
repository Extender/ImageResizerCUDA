#ifndef IO_H
#define IO_H

// Byte order is always little-endian.

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define extendBufferSize(bufferSize, pos) while(pos>=bufferSize) bufferSize*=2;

typedef size_t fs_t;

class io
{
public:
    static uint8_t readUInt8(char *&data);
    static uint16_t readUInt16(char *&data);
    static uint32_t readUInt32(char *&data);
    static uint64_t readUInt64(char *&data);
    static fs_t readFsT(char *&data);
    static float readFloat(char *&data, bool systemIsLittleEndian);
    static double readDouble(char *&data, bool systemIsLittleEndian);
    static double readDouble2(char *&data);
    static char *readFixedLengthData(char *&data, fs_t &length);
    static char *readZeroTerminatedData(char *&data);

    static uint8_t peekUInt8(char *data, fs_t pos);
    static uint16_t peekUInt16(char *data, fs_t pos);
    static uint32_t peekUInt32(char *data, fs_t pos);
    static uint64_t peekUInt64(char *data, fs_t pos);
    static fs_t peekFsT(char *data, fs_t pos);
    static double peekFloat(char *data, fs_t pos, bool systemIsLittleEndian);
    static double peekDouble(char *data, fs_t pos, bool systemIsLittleEndian);
    static double peekDouble2(char *data, fs_t pos);
    static char *peekFixedLengthData(char *data, fs_t pos, fs_t &length);
    static char *peekZeroTerminatedData(char *data, fs_t pos);
    static uint8_t posBasedReadUInt8(char *data, fs_t &pos);
    static uint16_t posBasedReadUInt16(char *data, fs_t &pos);
    static uint32_t posBasedReadUInt32(char *data, fs_t &pos);
    static uint64_t posBasedReadUInt64(char *data, fs_t &pos);
    static fs_t posBasedReadFsT(char *data, fs_t &pos);
    static float posBasedReadFloat(char *data, fs_t &pos, bool systemIsLittleEndian);
    static double posBasedReadDouble(char *data, fs_t &pos, bool systemIsLittleEndian);
    static double posBasedReadDouble2(char *data, fs_t &pos);
    static char *posBasedReadFixedLengthData(char *data, fs_t &pos, fs_t &length);
    static char *posBasedReadZeroTerminatedData(char *data, fs_t &pos);

    static void writeUInt8(char *data, uint8_t i, fs_t &pos);
    static void writeUInt16(char *data, uint16_t i, fs_t &pos);
    static void writeUInt32(char *data, uint32_t i, fs_t &pos);
    static void writeUInt64(char *data, uint64_t i, fs_t &pos);
    static void writeFsT(char *data, fs_t i, fs_t &pos);
    static void writeFloat(char *data, float i, fs_t &pos, bool systemIsLittleEndian);
    static void writeDouble(char *data, double i, fs_t &pos, bool systemIsLittleEndian);
    static void writeDouble2(char *data, double i, fs_t &pos);
    static void writeFixedLengthData(char *data, fs_t length, const char *in, fs_t &pos);
    static void writeZeroTerminatedData(char *data, const char *in, fs_t &pos);
    static void writeRawData(char *data, const char *in, fs_t length, fs_t &pos);

    static void putUInt8(char *data, uint8_t i, fs_t pos);
    static void putUInt16(char *data, uint16_t i, fs_t pos);
    static void putUInt32(char *data, uint32_t i, fs_t pos);
    static void putUInt64(char *data, uint64_t i, fs_t pos);
    static void putFsT(char *data, fs_t i, fs_t pos);
    static void putFloat(char *data, float i, fs_t pos, bool systemIsLittleEndian);
    static void putDouble(char *data, double i, fs_t pos, bool systemIsLittleEndian);
    static void putDouble2(char *data, double i, fs_t pos);
    static void putFixedLengthData(char *data, fs_t length, const char *in, fs_t pos);
    static void putZeroTerminatedData(char *data, const char *in, fs_t pos);
    static void putRawData(char *data, const char *in, fs_t length, fs_t pos);

    static void writeUInt8ToBuffer(char *&data, uint8_t i, fs_t &pos, fs_t &bufferSize);
    static void writeUInt16ToBuffer(char *&data, uint16_t i, fs_t &pos, fs_t &bufferSize);
    static void writeUInt32ToBuffer(char *&data, uint32_t i, fs_t &pos, fs_t &bufferSize);
    static void writeUInt64ToBuffer(char *&data, uint64_t i, fs_t &pos, fs_t &bufferSize);
    static void writeFsTToBuffer(char *&data, fs_t i, fs_t &pos, fs_t &bufferSize);
    static void writeFloatToBuffer(char *&data, float i, fs_t &pos, fs_t &bufferSize, bool systemIsLittleEndian);
    static void writeDoubleToBuffer(char *&data, double i, fs_t &pos, fs_t &bufferSize, bool systemIsLittleEndian);
    static void writeDoubleToBuffer2(char *&data, double i, fs_t &pos, fs_t &bufferSize);
    static void writeFixedLengthDataToBuffer(char *&data, fs_t length, const char *in, fs_t &pos, fs_t &bufferSize);
    static void writeZeroTerminatedDataToBuffer(char *&data, const char *in, fs_t &pos, fs_t &bufferSize);
    static void writeRawDataToBuffer(char *&data, const char *in, fs_t length, fs_t &pos, fs_t &bufferSize);
    static void writeRawDataToLongBuffer(char *&data, const char *in, uint64_t length, uint64_t &pos, uint64_t &bufferSize);
    static void writeRawCharToBuffer(char *&data, unsigned char in, fs_t &pos, fs_t &bufferSize);
    static void writeRawCharToLongBuffer(char *&data, unsigned char in, uint64_t &pos, uint64_t &bufferSize);

    static void terminateBuffer(char *&buffer, fs_t &pos, fs_t bufferSize);
    static void *fixedLengthDataToString(char *data, fs_t length);
    static bool bufferCheck(char *&buffer, fs_t pos, fs_t &bufferSize);
    static bool longBufferCheck(char *&buffer, uint64_t pos, uint64_t &bufferSize);

    static bool getSystemIsLittleEndian(); // Endianness depends on the machine the application runs on, not on the compiler!
    static uint16_t reverseUInt16ByteOrder(uint16_t i);
    static uint32_t reverseUInt32ByteOrder(uint32_t i);
    static uint64_t reverseUInt64ByteOrder(uint64_t i);
    static void reverseByteOrder(char *data, fs_t length);
    static uint8_t reverseUInt8BitOrder(uint8_t i, bool systemIsLittleEndian);
    static uint16_t reverseUInt16BitOrder(uint16_t i, bool systemIsLittleEndian);
    static uint32_t reverseUInt32BitOrder(uint32_t i, bool systemIsLittleEndian);
    static uint64_t reverseUInt64BitOrder(uint64_t i, bool systemIsLittleEndian);
    static void reverseBitOrder(char *data, fs_t lengthInBits, bool systemIsLittleEndian);
};

#endif // IO_H
