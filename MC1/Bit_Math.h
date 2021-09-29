/*
 * Bit_Math.h

 */

#ifndef E15_LAB_SRC_UTILS_BIT_MATH_H_
#define E15_LAB_SRC_UTILS_BIT_MATH_H_

#define SET_BIT(u8Var,BitNo)		u8Var |= (1<<BitNo)
#define CLR_BIT(u8Var,BitNo)		u8Var &= ~(1<<BitNo)
#define TOGGLE_BIT(u8Var,BitNo)		u8Var ^= (1<<BitNo)
#define GET_BIT(u8Var,BitNo)		((u8Var >> BitNo) & 0b00000001)
// Check if a specific bit is cleared in any register and return true if yes
#define BIT_IS_CLEAR(u8Var,BitNo) ( !(u8Var & (1<<BitNo)) )

#endif /* E15_LAB_SRC_UTILS_BIT_MATH_H_ */
