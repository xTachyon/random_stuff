
#include <cstdint>
#include <cstdio>
#include <cstdlib>

enum class Result {
    Unknown,
    False,
    True,
};
static void is_even_0_10(uint32_t x, int& result) {
    if (x == 0) goto yes;
    if (x == 1) goto no;
    if (x == 2) goto yes;
    if (x == 3) goto no;
    if (x == 4) goto yes;
    if (x == 5) goto no;
    if (x == 6) goto yes;
    if (x == 7) goto no;
    if (x == 8) goto yes;
    if (x == 9) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_10_20(uint32_t x, int& result) {
    if (x == 10) goto yes;
    if (x == 11) goto no;
    if (x == 12) goto yes;
    if (x == 13) goto no;
    if (x == 14) goto yes;
    if (x == 15) goto no;
    if (x == 16) goto yes;
    if (x == 17) goto no;
    if (x == 18) goto yes;
    if (x == 19) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_20_30(uint32_t x, int& result) {
    if (x == 20) goto yes;
    if (x == 21) goto no;
    if (x == 22) goto yes;
    if (x == 23) goto no;
    if (x == 24) goto yes;
    if (x == 25) goto no;
    if (x == 26) goto yes;
    if (x == 27) goto no;
    if (x == 28) goto yes;
    if (x == 29) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_30_40(uint32_t x, int& result) {
    if (x == 30) goto yes;
    if (x == 31) goto no;
    if (x == 32) goto yes;
    if (x == 33) goto no;
    if (x == 34) goto yes;
    if (x == 35) goto no;
    if (x == 36) goto yes;
    if (x == 37) goto no;
    if (x == 38) goto yes;
    if (x == 39) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_40_50(uint32_t x, int& result) {
    if (x == 40) goto yes;
    if (x == 41) goto no;
    if (x == 42) goto yes;
    if (x == 43) goto no;
    if (x == 44) goto yes;
    if (x == 45) goto no;
    if (x == 46) goto yes;
    if (x == 47) goto no;
    if (x == 48) goto yes;
    if (x == 49) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_50_60(uint32_t x, int& result) {
    if (x == 50) goto yes;
    if (x == 51) goto no;
    if (x == 52) goto yes;
    if (x == 53) goto no;
    if (x == 54) goto yes;
    if (x == 55) goto no;
    if (x == 56) goto yes;
    if (x == 57) goto no;
    if (x == 58) goto yes;
    if (x == 59) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_60_70(uint32_t x, int& result) {
    if (x == 60) goto yes;
    if (x == 61) goto no;
    if (x == 62) goto yes;
    if (x == 63) goto no;
    if (x == 64) goto yes;
    if (x == 65) goto no;
    if (x == 66) goto yes;
    if (x == 67) goto no;
    if (x == 68) goto yes;
    if (x == 69) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_70_80(uint32_t x, int& result) {
    if (x == 70) goto yes;
    if (x == 71) goto no;
    if (x == 72) goto yes;
    if (x == 73) goto no;
    if (x == 74) goto yes;
    if (x == 75) goto no;
    if (x == 76) goto yes;
    if (x == 77) goto no;
    if (x == 78) goto yes;
    if (x == 79) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_80_90(uint32_t x, int& result) {
    if (x == 80) goto yes;
    if (x == 81) goto no;
    if (x == 82) goto yes;
    if (x == 83) goto no;
    if (x == 84) goto yes;
    if (x == 85) goto no;
    if (x == 86) goto yes;
    if (x == 87) goto no;
    if (x == 88) goto yes;
    if (x == 89) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_90_100(uint32_t x, int& result) {
    if (x == 90) goto yes;
    if (x == 91) goto no;
    if (x == 92) goto yes;
    if (x == 93) goto no;
    if (x == 94) goto yes;
    if (x == 95) goto no;
    if (x == 96) goto yes;
    if (x == 97) goto no;
    if (x == 98) goto yes;
    if (x == 99) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_100_110(uint32_t x, int& result) {
    if (x == 100) goto yes;
    if (x == 101) goto no;
    if (x == 102) goto yes;
    if (x == 103) goto no;
    if (x == 104) goto yes;
    if (x == 105) goto no;
    if (x == 106) goto yes;
    if (x == 107) goto no;
    if (x == 108) goto yes;
    if (x == 109) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_110_120(uint32_t x, int& result) {
    if (x == 110) goto yes;
    if (x == 111) goto no;
    if (x == 112) goto yes;
    if (x == 113) goto no;
    if (x == 114) goto yes;
    if (x == 115) goto no;
    if (x == 116) goto yes;
    if (x == 117) goto no;
    if (x == 118) goto yes;
    if (x == 119) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_120_130(uint32_t x, int& result) {
    if (x == 120) goto yes;
    if (x == 121) goto no;
    if (x == 122) goto yes;
    if (x == 123) goto no;
    if (x == 124) goto yes;
    if (x == 125) goto no;
    if (x == 126) goto yes;
    if (x == 127) goto no;
    if (x == 128) goto yes;
    if (x == 129) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_130_140(uint32_t x, int& result) {
    if (x == 130) goto yes;
    if (x == 131) goto no;
    if (x == 132) goto yes;
    if (x == 133) goto no;
    if (x == 134) goto yes;
    if (x == 135) goto no;
    if (x == 136) goto yes;
    if (x == 137) goto no;
    if (x == 138) goto yes;
    if (x == 139) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_140_150(uint32_t x, int& result) {
    if (x == 140) goto yes;
    if (x == 141) goto no;
    if (x == 142) goto yes;
    if (x == 143) goto no;
    if (x == 144) goto yes;
    if (x == 145) goto no;
    if (x == 146) goto yes;
    if (x == 147) goto no;
    if (x == 148) goto yes;
    if (x == 149) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_150_160(uint32_t x, int& result) {
    if (x == 150) goto yes;
    if (x == 151) goto no;
    if (x == 152) goto yes;
    if (x == 153) goto no;
    if (x == 154) goto yes;
    if (x == 155) goto no;
    if (x == 156) goto yes;
    if (x == 157) goto no;
    if (x == 158) goto yes;
    if (x == 159) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_160_170(uint32_t x, int& result) {
    if (x == 160) goto yes;
    if (x == 161) goto no;
    if (x == 162) goto yes;
    if (x == 163) goto no;
    if (x == 164) goto yes;
    if (x == 165) goto no;
    if (x == 166) goto yes;
    if (x == 167) goto no;
    if (x == 168) goto yes;
    if (x == 169) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_170_180(uint32_t x, int& result) {
    if (x == 170) goto yes;
    if (x == 171) goto no;
    if (x == 172) goto yes;
    if (x == 173) goto no;
    if (x == 174) goto yes;
    if (x == 175) goto no;
    if (x == 176) goto yes;
    if (x == 177) goto no;
    if (x == 178) goto yes;
    if (x == 179) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_180_190(uint32_t x, int& result) {
    if (x == 180) goto yes;
    if (x == 181) goto no;
    if (x == 182) goto yes;
    if (x == 183) goto no;
    if (x == 184) goto yes;
    if (x == 185) goto no;
    if (x == 186) goto yes;
    if (x == 187) goto no;
    if (x == 188) goto yes;
    if (x == 189) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_190_200(uint32_t x, int& result) {
    if (x == 190) goto yes;
    if (x == 191) goto no;
    if (x == 192) goto yes;
    if (x == 193) goto no;
    if (x == 194) goto yes;
    if (x == 195) goto no;
    if (x == 196) goto yes;
    if (x == 197) goto no;
    if (x == 198) goto yes;
    if (x == 199) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_200_210(uint32_t x, int& result) {
    if (x == 200) goto yes;
    if (x == 201) goto no;
    if (x == 202) goto yes;
    if (x == 203) goto no;
    if (x == 204) goto yes;
    if (x == 205) goto no;
    if (x == 206) goto yes;
    if (x == 207) goto no;
    if (x == 208) goto yes;
    if (x == 209) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_210_220(uint32_t x, int& result) {
    if (x == 210) goto yes;
    if (x == 211) goto no;
    if (x == 212) goto yes;
    if (x == 213) goto no;
    if (x == 214) goto yes;
    if (x == 215) goto no;
    if (x == 216) goto yes;
    if (x == 217) goto no;
    if (x == 218) goto yes;
    if (x == 219) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_220_230(uint32_t x, int& result) {
    if (x == 220) goto yes;
    if (x == 221) goto no;
    if (x == 222) goto yes;
    if (x == 223) goto no;
    if (x == 224) goto yes;
    if (x == 225) goto no;
    if (x == 226) goto yes;
    if (x == 227) goto no;
    if (x == 228) goto yes;
    if (x == 229) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_230_240(uint32_t x, int& result) {
    if (x == 230) goto yes;
    if (x == 231) goto no;
    if (x == 232) goto yes;
    if (x == 233) goto no;
    if (x == 234) goto yes;
    if (x == 235) goto no;
    if (x == 236) goto yes;
    if (x == 237) goto no;
    if (x == 238) goto yes;
    if (x == 239) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_240_250(uint32_t x, int& result) {
    if (x == 240) goto yes;
    if (x == 241) goto no;
    if (x == 242) goto yes;
    if (x == 243) goto no;
    if (x == 244) goto yes;
    if (x == 245) goto no;
    if (x == 246) goto yes;
    if (x == 247) goto no;
    if (x == 248) goto yes;
    if (x == 249) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_250_260(uint32_t x, int& result) {
    if (x == 250) goto yes;
    if (x == 251) goto no;
    if (x == 252) goto yes;
    if (x == 253) goto no;
    if (x == 254) goto yes;
    if (x == 255) goto no;
    if (x == 256) goto yes;
    if (x == 257) goto no;
    if (x == 258) goto yes;
    if (x == 259) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_260_270(uint32_t x, int& result) {
    if (x == 260) goto yes;
    if (x == 261) goto no;
    if (x == 262) goto yes;
    if (x == 263) goto no;
    if (x == 264) goto yes;
    if (x == 265) goto no;
    if (x == 266) goto yes;
    if (x == 267) goto no;
    if (x == 268) goto yes;
    if (x == 269) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_270_280(uint32_t x, int& result) {
    if (x == 270) goto yes;
    if (x == 271) goto no;
    if (x == 272) goto yes;
    if (x == 273) goto no;
    if (x == 274) goto yes;
    if (x == 275) goto no;
    if (x == 276) goto yes;
    if (x == 277) goto no;
    if (x == 278) goto yes;
    if (x == 279) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_280_290(uint32_t x, int& result) {
    if (x == 280) goto yes;
    if (x == 281) goto no;
    if (x == 282) goto yes;
    if (x == 283) goto no;
    if (x == 284) goto yes;
    if (x == 285) goto no;
    if (x == 286) goto yes;
    if (x == 287) goto no;
    if (x == 288) goto yes;
    if (x == 289) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_290_300(uint32_t x, int& result) {
    if (x == 290) goto yes;
    if (x == 291) goto no;
    if (x == 292) goto yes;
    if (x == 293) goto no;
    if (x == 294) goto yes;
    if (x == 295) goto no;
    if (x == 296) goto yes;
    if (x == 297) goto no;
    if (x == 298) goto yes;
    if (x == 299) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_300_310(uint32_t x, int& result) {
    if (x == 300) goto yes;
    if (x == 301) goto no;
    if (x == 302) goto yes;
    if (x == 303) goto no;
    if (x == 304) goto yes;
    if (x == 305) goto no;
    if (x == 306) goto yes;
    if (x == 307) goto no;
    if (x == 308) goto yes;
    if (x == 309) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_310_320(uint32_t x, int& result) {
    if (x == 310) goto yes;
    if (x == 311) goto no;
    if (x == 312) goto yes;
    if (x == 313) goto no;
    if (x == 314) goto yes;
    if (x == 315) goto no;
    if (x == 316) goto yes;
    if (x == 317) goto no;
    if (x == 318) goto yes;
    if (x == 319) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_320_330(uint32_t x, int& result) {
    if (x == 320) goto yes;
    if (x == 321) goto no;
    if (x == 322) goto yes;
    if (x == 323) goto no;
    if (x == 324) goto yes;
    if (x == 325) goto no;
    if (x == 326) goto yes;
    if (x == 327) goto no;
    if (x == 328) goto yes;
    if (x == 329) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_330_340(uint32_t x, int& result) {
    if (x == 330) goto yes;
    if (x == 331) goto no;
    if (x == 332) goto yes;
    if (x == 333) goto no;
    if (x == 334) goto yes;
    if (x == 335) goto no;
    if (x == 336) goto yes;
    if (x == 337) goto no;
    if (x == 338) goto yes;
    if (x == 339) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_340_350(uint32_t x, int& result) {
    if (x == 340) goto yes;
    if (x == 341) goto no;
    if (x == 342) goto yes;
    if (x == 343) goto no;
    if (x == 344) goto yes;
    if (x == 345) goto no;
    if (x == 346) goto yes;
    if (x == 347) goto no;
    if (x == 348) goto yes;
    if (x == 349) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_350_360(uint32_t x, int& result) {
    if (x == 350) goto yes;
    if (x == 351) goto no;
    if (x == 352) goto yes;
    if (x == 353) goto no;
    if (x == 354) goto yes;
    if (x == 355) goto no;
    if (x == 356) goto yes;
    if (x == 357) goto no;
    if (x == 358) goto yes;
    if (x == 359) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_360_370(uint32_t x, int& result) {
    if (x == 360) goto yes;
    if (x == 361) goto no;
    if (x == 362) goto yes;
    if (x == 363) goto no;
    if (x == 364) goto yes;
    if (x == 365) goto no;
    if (x == 366) goto yes;
    if (x == 367) goto no;
    if (x == 368) goto yes;
    if (x == 369) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_370_380(uint32_t x, int& result) {
    if (x == 370) goto yes;
    if (x == 371) goto no;
    if (x == 372) goto yes;
    if (x == 373) goto no;
    if (x == 374) goto yes;
    if (x == 375) goto no;
    if (x == 376) goto yes;
    if (x == 377) goto no;
    if (x == 378) goto yes;
    if (x == 379) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_380_390(uint32_t x, int& result) {
    if (x == 380) goto yes;
    if (x == 381) goto no;
    if (x == 382) goto yes;
    if (x == 383) goto no;
    if (x == 384) goto yes;
    if (x == 385) goto no;
    if (x == 386) goto yes;
    if (x == 387) goto no;
    if (x == 388) goto yes;
    if (x == 389) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_390_400(uint32_t x, int& result) {
    if (x == 390) goto yes;
    if (x == 391) goto no;
    if (x == 392) goto yes;
    if (x == 393) goto no;
    if (x == 394) goto yes;
    if (x == 395) goto no;
    if (x == 396) goto yes;
    if (x == 397) goto no;
    if (x == 398) goto yes;
    if (x == 399) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_400_410(uint32_t x, int& result) {
    if (x == 400) goto yes;
    if (x == 401) goto no;
    if (x == 402) goto yes;
    if (x == 403) goto no;
    if (x == 404) goto yes;
    if (x == 405) goto no;
    if (x == 406) goto yes;
    if (x == 407) goto no;
    if (x == 408) goto yes;
    if (x == 409) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_410_420(uint32_t x, int& result) {
    if (x == 410) goto yes;
    if (x == 411) goto no;
    if (x == 412) goto yes;
    if (x == 413) goto no;
    if (x == 414) goto yes;
    if (x == 415) goto no;
    if (x == 416) goto yes;
    if (x == 417) goto no;
    if (x == 418) goto yes;
    if (x == 419) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_420_430(uint32_t x, int& result) {
    if (x == 420) goto yes;
    if (x == 421) goto no;
    if (x == 422) goto yes;
    if (x == 423) goto no;
    if (x == 424) goto yes;
    if (x == 425) goto no;
    if (x == 426) goto yes;
    if (x == 427) goto no;
    if (x == 428) goto yes;
    if (x == 429) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_430_440(uint32_t x, int& result) {
    if (x == 430) goto yes;
    if (x == 431) goto no;
    if (x == 432) goto yes;
    if (x == 433) goto no;
    if (x == 434) goto yes;
    if (x == 435) goto no;
    if (x == 436) goto yes;
    if (x == 437) goto no;
    if (x == 438) goto yes;
    if (x == 439) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_440_450(uint32_t x, int& result) {
    if (x == 440) goto yes;
    if (x == 441) goto no;
    if (x == 442) goto yes;
    if (x == 443) goto no;
    if (x == 444) goto yes;
    if (x == 445) goto no;
    if (x == 446) goto yes;
    if (x == 447) goto no;
    if (x == 448) goto yes;
    if (x == 449) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_450_460(uint32_t x, int& result) {
    if (x == 450) goto yes;
    if (x == 451) goto no;
    if (x == 452) goto yes;
    if (x == 453) goto no;
    if (x == 454) goto yes;
    if (x == 455) goto no;
    if (x == 456) goto yes;
    if (x == 457) goto no;
    if (x == 458) goto yes;
    if (x == 459) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_460_470(uint32_t x, int& result) {
    if (x == 460) goto yes;
    if (x == 461) goto no;
    if (x == 462) goto yes;
    if (x == 463) goto no;
    if (x == 464) goto yes;
    if (x == 465) goto no;
    if (x == 466) goto yes;
    if (x == 467) goto no;
    if (x == 468) goto yes;
    if (x == 469) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_470_480(uint32_t x, int& result) {
    if (x == 470) goto yes;
    if (x == 471) goto no;
    if (x == 472) goto yes;
    if (x == 473) goto no;
    if (x == 474) goto yes;
    if (x == 475) goto no;
    if (x == 476) goto yes;
    if (x == 477) goto no;
    if (x == 478) goto yes;
    if (x == 479) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_480_490(uint32_t x, int& result) {
    if (x == 480) goto yes;
    if (x == 481) goto no;
    if (x == 482) goto yes;
    if (x == 483) goto no;
    if (x == 484) goto yes;
    if (x == 485) goto no;
    if (x == 486) goto yes;
    if (x == 487) goto no;
    if (x == 488) goto yes;
    if (x == 489) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}
static void is_even_490_500(uint32_t x, int& result) {
    if (x == 490) goto yes;
    if (x == 491) goto no;
    if (x == 492) goto yes;
    if (x == 493) goto no;
    if (x == 494) goto yes;
    if (x == 495) goto no;
    if (x == 496) goto yes;
    if (x == 497) goto no;
    if (x == 498) goto yes;
    if (x == 499) goto no;

    result = false;
    return;
yes:
    result = true;
    return;
no:
    result = false;
    return;
}

bool is_even(uint32_t x) {
#define c(name)                \
    {                          \
        int result;            \
        name(x, result); \
        if (result) {            \
            return result;     \
        }                      \
    }
   c(is_even_0_10);
   c(is_even_10_20);
   c(is_even_20_30);
   c(is_even_30_40);
   c(is_even_40_50);
   c(is_even_50_60);
   c(is_even_60_70);
   c(is_even_70_80);
   c(is_even_80_90);
   c(is_even_90_100);
   c(is_even_100_110);
   c(is_even_110_120);
   c(is_even_120_130);
   c(is_even_130_140);
   c(is_even_140_150);
   c(is_even_150_160);
   c(is_even_160_170);
   c(is_even_170_180);
   c(is_even_180_190);
   c(is_even_190_200);
   c(is_even_200_210);
   c(is_even_210_220);
   c(is_even_220_230);
   c(is_even_230_240);
   c(is_even_240_250);
   c(is_even_250_260);
   c(is_even_260_270);
   c(is_even_270_280);
   c(is_even_280_290);
   c(is_even_290_300);
   c(is_even_300_310);
   c(is_even_310_320);
   c(is_even_320_330);
   c(is_even_330_340);
   c(is_even_340_350);
   c(is_even_350_360);
   c(is_even_360_370);
   c(is_even_370_380);
   c(is_even_380_390);
   c(is_even_390_400);
   c(is_even_400_410);
   c(is_even_410_420);
   c(is_even_420_430);
   c(is_even_430_440);
   c(is_even_440_450);
   c(is_even_450_460);
   c(is_even_460_470);
   c(is_even_470_480);
   c(is_even_480_490);
   c(is_even_490_500);

    return false;
}

int main(int argc, char** argv) {
    uint32_t x = atoi(argv[1]);
    printf("%s", is_even(x) ? "even" : "odd");
}
