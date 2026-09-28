/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y){
  return ~(~x|~y);
}


/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
  return ~(x&y)&~(~x&~y);
}



/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    int negX=(x>>31)&1;
    int negY=(y>>31)&1;
    if (negX&&negY){
        return 1;
    }
    if (!negX &&!negY) {
        return !(!x^!y);
    }
    return 0;
}
/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int res=0;
    int shift;
    shift=((v>>16)>0)<<4;
    res|=shift;
    v=v>>shift;
    shift=((v>>8)>0)<<3;
    res|=shift;
    v=v>>shift;
    shift=((v>>4)>0)<<2;
    res|=shift;
    v=v>>shift;
    shift=((v>>2)>0)<<1;
    res|=shift;
    v=v>>shift;
    shift=((v>>1)>0)<<0;
    res|=shift;
    return res;
}



/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int shift_n =n<<3;
    int shift_m =m<<3;
    int bn=(x>>shift_n) & 0xff;
    int bm=(x>>shift_m) & 0xff;
    int mask=(0xff<< shift_n)|(0xff<<shift_m);
    x=x& ~mask;
    x=x|(bn << shift_m)|(bm << shift_n);
    return x;
}


/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v){
    v=((v>>1)&0x55555555)|((v&0x55555555)<<1);
    v=((v>>2)&0x33333333)|((v&0x33333333)<<2);
    v=((v>>4)&0x0F0F0F0F)|((v&0x0F0F0F0F)<<4);
    v=((v>>8)&0x00FF00FF)|((v&0x00FF00FF)<<8);
    v=((v>>16)&0x0000FFFF)|((v&0x0000FFFF)<<16);
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x,int n){
    int shifted=x>>n;
    int mask=~((1<<31)>>n<<1);
    return shifted&mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x){
    int z=~x;
    z|=z>>1;
    z|=z>>2 ;
    z|=z>>4;
    z|=z>>8;
    z|=z>>16;
    int pop=(z&0x55555555)+((z>>1)&0x55555555);
    pop=(pop&0x33333333)+((pop>>2)&0x33333333);
    pop=(pop&0x0F0F0F0F)+((pop>>4)&0x0F0F0F0F);
    pop=(pop&0x00FF00FF)+((pop>>8)&0x00FF00FF);
    pop=(pop&0x0000FFFF)+((pop>>16)&0x0000FFFF);
    return 32+~pop+1;
}




/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned sign,exp,frac,abs_x;
    unsigned shift;
    unsigned guard,round_bit,sticky;
    if (x==0){
        return 0U;
    }
    if (x==0x80000000) {
        return 0xcf000000U;
    }
    sign = x >> 31;
    if (sign) {
        abs_x = -x;
    } else {
        abs_x = x;
    }
    shift = 31;
    while (!(abs_x & (1U << shift)) ) {
        shift = shift - 1;
    }
    exp = shift + 127;
    abs_x = abs_x << (31 - shift);
    guard = (abs_x >> 8) & 1;
    round_bit = (abs_x >> 7) & 1;
    sticky = abs_x & 0x7F;

    frac = abs_x >> 9;
    if ( guard & ( round_bit | sticky | (frac & 1) ) ) {
        frac = frac + 1;
        if (frac == 0x800000U) {
            exp = exp + 1;
            frac = 0U;
        }
    }
    return (sign << 31) | (exp << 23) | frac;
}











/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf){
    unsigned sign=uf&0x80000000;
    unsigned exp=(uf>>23)&0xFF;
    unsigned frac=uf&0x7FFFFF;
        if(exp==0xFF){
            return uf;
        }
        if(exp==0){
            frac=frac<<1;
            return sign|frac;
            }
        exp=exp+1;
        return sign|(exp<<23)|frac;
    }

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;
    unsigned exp = (uf2 >> 20) & 0x7FF;
    unsigned frac_h = uf2 & 0xFFFFF;
    unsigned frac_l = uf1;
    int E = exp - 1023;
    unsigned val;
    if (E < 0) {
        return 0;
    }
    if (E >= 31) {
        return 0x80000000;
    }
    if (E > 20) {
        unsigned shift = E - 20;
        val = ((1U << 20) | frac_h) << shift;
        val = val | (frac_l >> (32 - shift));
    } else {
        unsigned shift = 20 - E;
        val = ((1U << 20) | frac_h) >> shift;
    }
    if (sign) {
        val = -val;
    }
    return val;
}



/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    unsigned cond_inf = (x > 127);
    unsigned mask_inf = ~cond_inf + 1U;
    unsigned val_inf = 0x7F800000U;
    unsigned cond_norm = (x >= -126) && (x <= 127);
    unsigned mask_norm = ~cond_norm + 1U;
    unsigned val_norm = (x + 127) << 23;

    unsigned cond_denorm = (x >= -149) && (x <= -127);
    unsigned mask_denorm = ~cond_denorm + 1U;
    unsigned val_denorm = 1U << (x + 149);

    unsigned res = (mask_inf & val_inf) | (mask_norm & val_norm) | (mask_denorm & val_denorm);
    return res;
}
