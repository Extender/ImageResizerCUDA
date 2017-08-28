#ifndef COLORDEFS_H
#define COLORDEFS_H

#ifndef getByte
#define getByte(value,byte) (((value)>>((byte)*8))&0xFF)
#endif
#ifndef getAlpha
#define getAlpha(x) ((x>>24)&0xff)
#endif
#ifndef getRed
#define getRed(x) ((x>>16)&0xff)
#endif
#ifndef getGreen
#define getGreen(x) ((x>>8)&0xff)
#endif
#ifndef getBlue
#define getBlue(x) (x&0xff)
#endif
#ifndef getColor
#define getColor(a,r,g,b) ((uint32_t)((((uint32_t)a)<<24)|(((uint32_t)r)<<16)|(((uint32_t)g)<<8)|((uint32_t)b)))
#endif
#ifndef doubleDiv
#define doubleDiv(a,b) ((double)((double)(a))/((double)(b)))
#endif
#ifndef floatDiv
#define floatDiv(a,b) ((float)((float)(a))/((float)(b)))
#endif
#ifndef pow2
#define pow2(a) ((a)*(a))
#endif
#ifndef pow2f
#define pow2f(a) ((float)(((float)a)*((float)a)))
#endif
#ifndef getColorError
#define getColorError(a,b) floatDiv(sqrt((float)pow2f(getRed(a)-getRed(b))+pow2f(getGreen(a)-getGreen(b))+pow2f(getBlue(a)-getBlue(b))),sqrt(195075.0f))
#endif
#ifndef getLinearColorError
#define getLinearColorError(a,b) floatDiv((floatDiv(abs(getRed(a)-getRed(b)),255.0f)+floatDiv(abs(getGreen(a)-getGreen(b)),255.0f)+floatDiv(abs(getBlue(a)-getBlue(b))),255.0f),3.0f)
#endif
#ifndef ifGTZero
#define ifGTZero(x) ((x)>0?(x):0)
#endif
#ifndef ifGTZeroArg
#define ifGTZeroArg(x,y) ((x)>0?(y):0)
#endif

#endif // COLORDEFS_H
