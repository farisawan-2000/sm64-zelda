.definelabel func_0027A010, 0x8027A010

.headersize 0x80245000

.org 0x803112f0

addiu $sp, $sp, -0x18
sw    $ra, 0x14($sp)
lui   $a0, 0x8033
lh    $a0, -0x220c($a0)
move  $a1, $zero
addiu $a2, $zero, 0x18
jal   func_0027A010_ovl0
 addiu $a0, $a0, -1
slti  $at, $v0, 1
bnez  $at, @L04C87194_ovl0
 nop   
lui   $t6, 0x8036
lw    $t6, 0x1160($t6)
sh    $zero, 0x74($t6)
@L04C87194_ovl0:
b     @L04C8719C_ovl0
 nop   
@L04C8719C_ovl0:
lw    $ra, 0x14($sp)
addiu $sp, $sp, 0x18
jr    $ra
nop