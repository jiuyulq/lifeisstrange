#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

struct Decoder {
    static string decode(const string& p_what)
    {
        string char_ignore = "!\"#$%&'()*+-/:;<=>@[\\]^_`{|}~";
        string char_dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?  "; //末尾两个空格，最后一位暂不可知
        map<char, int> codemap;
        for (int i = 0; i < char_dict.length(); ++i) {
            codemap.insert(std::make_pair(char_dict[i], i + 1));
        }
        string message;
        long long snow_ball = 2;

        for (int i = 0; i < p_what.length(); ++i) {
            long long trans = snow_ball - 1;
            snow_ball *= 2;
            if (snow_ball > 67) {
                snow_ball = snow_ball % 67 + 67;
            }

            bool is_ignore = false;
            for (auto& w : char_ignore) {
                if (p_what[i] == w) {
                    message += p_what[i];
                    is_ignore = true;
                    break;
                }
            }

            if (is_ignore) {
                continue;
            }

            long long span;
            for (auto& w : codemap) {
                span = trans * w.second % 67;
                if (char_dict[(w.second - 1 + span) % 67] == p_what[i]) {
                    message += w.first;
                    break;
                }
            }
        }

        return message;
    }
};

/*

bdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLir
dhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhp
!@#$%^&*()_+-
bdfhjlnprtvxzBDFHJLNPRTVXZ
dhlptxBFJNRVZ37,aeimquyCGK
hpxFNV3,emuCKS08bjrzHPX5 g

a***b***c***d***e***f***g***h***i***j***k***l***m***n***o***p***q***r***s***t***u***v***w***x***y***z***
b***d***f***h***j***l***n***p***r***t***v***x***z***B***D***F***H***J***L***N***P***R***T***V***X***Z***
  97***  98***  99*** 100*** 101*** 102*** 103*** 104*** 105*** 106*** 107*** 108*** 109*** 110*** 111*** 112*** 113*** 114*** 115*** 116*** 117*** 118*** 119*** 120*** 121*** 122***
  98*** 100*** 102*** 104*** 106*** 108*** 110*** 112*** 114*** 116*** 118*** 120*** 122***  66***  68***  70***  72***  74***  76***  78***  80***  82***  84***  86***  88***  90***

_a   ***    _b***   _c***_   d***    _e***_f***_g***_h***_i***_j***_k***_l***_m***_n***_o***_p***_q***_r***_s***_t***_u***_v***_w***_x***_y***_z***
_d   ***    _h***   _l***    _p***   _t***_x***_B***_F***_J***_N***_R***_V***_Z***_3***_7***_,***_a***_e***_i***_m***_q***_u***_y***_C***_G***_K***
_  97***_  98***_  99***_ 100***_ 101***_ 102***_ 103***_ 104***_ 105***_ 106***_ 107***_ 108***_ 109***_ 110***_ 111***_ 112***_ 113***_ 114***_ 115***_ 116***_ 117***_ 118***_ 119***_ 120***_ 121***_ 122***
_ 100***_ 104***_ 108***_ 112***_ 116***_ 120***_  66***_  70***_  74***_  78***_  82***_  86***_  90***_  51***_  55***_  44***_  97***_ 101***_ 105***_ 109***_ 113***_ 117***_ 121***_  67***_  71***_  75***

__a***__b***__c***__d***__e***__f***__g***__h***__i***__j***__k***__l***__m***__n***__o***__p***__q***__r***__s***__t***__u***__v***__w***__x***__y***__z***
__h***__p***__x***__F***__N***__V***__3***__,***__e***__m***__u***__C***__K***__S***__0***__8***__b***__j***__r***__z***__H***__P***__X***__5***__ ***__g***
__  97***__  98***__  99***__ 100***__ 101***__ 102***__ 103***__ 104***__ 105***__ 106***__ 107***__ 108***__ 109***__ 110***__ 111***__ 112***__ 113***__ 114***__ 115***__ 116***__ 117***__ 118***__ 119***__ 120***__ 121***__ 122***
__ 104***__ 112***__ 120***__  70***__  78***__  86***__  51***__  44***__ 101***__ 109***__ 117***__  67***__  75***__  83***__  48***__  56***__  98***__ 106***__ 114***__ 122***__  72***__  80***__  88***__  53***__  32***__ 103***

___a***___b***___c***___d***___e***___f***___g***___h***___i***___j***___k***___l***___m***___n***___o***___p***___q***___r***___s***___t***___u***___v***___w***___x***___y***___z***
___p***___F***___V***___,***___m***___C***___S***___8***___j***___z***___P***___5***___g***___w***___M***___2***___d***___t***___J***___Z***___a***___q***___G***___W***___?***___n***
___  97***___  98***___  99***___ 100***___ 101***___ 102***___ 103***___ 104***___ 105***___ 106***___ 107***___ 108***___ 109***___ 110***___ 111***___ 112***___ 113***___ 114***___ 115***___ 116***___ 117***___ 118***___ 119***___ 120***___ 121***___ 122***
___ 112***___  70***___  86***___  44***___ 109***___  67***___  83***___  56***___ 106***___ 122***___  80***___  53***___ 103***___ 119***___  77***___  50***___ 100***___ 116***___  74***___  90***___  97***___ 113***___  71***___  87***___  63***___ 110***


124 == 66
*/

/*

#测试
!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
!"#$%&'()*+N-4/8h35haMrX8:;<=>H@NkrBNVFcr7HDYq?5M5ieYX.Zwr[\]^_`HbfpNCwQmndAy6bNrTS.eJ4qOC{|}~
#不变
!"#$%&'()*+-/:;<=>@[\]^_`{|}~
#变化
,  .  0123456789 ?  ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz
44 46 48-57      63 65-90                      97-122

AAAAA
10oD7


,.0123456789?ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
mU2pSWpbkJG2amvJ3mC,fJ0a7IH.WkWrjIG6KTJadlFm5TszBh1XYdmJyw6jeUHo5

*/

/*
ascii 参考
space ,   .   0   1   2   3   4   5   6   7   8   9   ?   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
0     44  46  48  49  50  51  52  53  54  55  56  57  63  65  66  67  68  69  70  71  72  73  74  75  76  77  78  79

P   Q   R   S   T   U   V   W   X   Y   Z   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q
80  81  82  83  84  85  86  87  88  89  90  97  98  99 100 101 102 103 104 105 106 107 108 109 110 111 112 113

r   s   t   u   v   w   x   y   z
114 115 116 117 118 119 120 121 122
总计67个.  还有一个未知

a   b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z
97  98  99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122

A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z
65  66  67  68  69  70  71  72  73  74  75  76  77  78  79  80  81  82  83  84  85  86  87  88  89  90

0   1   2   3   4   5   6   7   8   9   .   ,   ?    space  *
48  49  50  51  52  53  54  55  56  57  46  44  63    0     *



/*
AAAAAAAAAAAAAAAAA
1OoD70MkvRuPqHabdhpF,82Qs
====
BBBBBBBBBBBBBBB
3SwTyXG ?.6YIcflxVC5WE94U
====
CCCCCCCCCCCCCCCCCCCCCC
5WE94UA1OoD70MkvRuPqHabdh
====
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
70MkvRuPqHabdhpF,82QsLirJ
====
EEEEEEEEEEEEEEEEEEEEEEEEEE
94UA1OoD70MkvRuPqHabdhpF,
testend



*/
/*
abcdefghijklmnopqrstuvwxyz
bdfhjlnprtvxzBDFHJLNPRTVXZ
+1 +2 +4 +8
*/

/*
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
dhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLirJejtN
+2 +4 +8 +16

====
ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
flxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD7
+3 +6 +12 +24

====
dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
hpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLirJejtNm
+4 +8
====
zzzzzzzzzzzzzzzzzzzzzzzz
ZKgnB3SwTyXG ?.6YIcflxVC
====
eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
jtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLirJejtNmzZKgnB3SwTyXG
====

?.6YIcflxVC5WE94UA1OoD70MkvRuPqHabdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94U

*/
