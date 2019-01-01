#include <iostream>
#include <map>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::multiset;
using std::vector;

#define POKER_NUM (5)

#define POKER_T (10)
#define POKER_J (11)
#define POKER_Q (12)
#define POKER_K (13)
#define POKER_A (14)

enum class Result {
    Win,
    Loss,
    Tie
};

enum kPokerType {
    straight_flush = 1, //2H 3H 4H 5H 6H
    four_of_a_kind = 2, //AS AD AC AH JD
    full_house = 3, //2S AH 2H AS AC
    flush = 4, //2H 3H 5H 6H 7H
    straight = 5, //2S 3H 4H 5S 6S
    three_of_a_kind = 6, //AH AC 5H 6H AS
    two_pair = 7, //2S 2H 4H 5S 4C
    pair = 8, //AH AC 5H 6H 7S
    nothing = 9 //AD 4C 5H 6H 2C
};

//存储处理后的PokerHand
//For Example:
//"AS AD AC AH JD"  => m_poker_type = four_of_a_kind; m_poker = [14, 11]
//"2S 2H 4H 5S 4C"  => m_poker_type = two_pair; m_poker = [4, 2, 5]
//"AH AC 5H 6H 7S"  => m_poker_type = pair; m_poker=[14, 5, 6 7];
//首先存储一个类型，然后存储该类型标志牌到m_poker中（由大到小），再存储其余牌（由小到大）.
struct PokerHand {
    kPokerType m_poker_type;
    vector<int> m_poker;
    PokerHand(const char* pokerhand);

    bool IsStraight(multiset<int>& pokerhand);

    //将牌的大小转为数字
    //"KS 2H 5C JD TD"  =>  [2, 5, 10, 11, 13]
    multiset<int> ConvertToNumber(const char* pokerhand);
    void ClassifyPoker();
};

Result compare(const PokerHand& player, const PokerHand& opponent);

Result compare_straight_flush(const PokerHand& player, const PokerHand& opponent);
Result compare_four_of_a_kind(const PokerHand& player, const PokerHand& opponent);
Result compare_full_house(const PokerHand& player, const PokerHand& opponent);
Result compare_flush(const PokerHand& player, const PokerHand& opponent);
Result compare_straight(const PokerHand& player, const PokerHand& opponent);
Result compare_three_of_a_kind(const PokerHand& player, const PokerHand& opponent);
Result compare_two_pair(const PokerHand& player, const PokerHand& opponent);
Result compare_pair(const PokerHand& player, const PokerHand& opponent);
Result compare_nothing(const PokerHand& player, const PokerHand& opponent);

bool PokerHand::IsStraight(multiset<int>& pokerhand)
{
    multiset<int>::iterator it_begin = pokerhand.begin();
    multiset<int>::iterator it_end = --pokerhand.end();
    if (4 == (*it_end - *it_begin)) {
        return true;
    } else if ((POKER_A == *it_end) && (5 == *(--it_end))) { //as A 2 3 4 5 => 2 3 4 5 14
        return true;
    }
    return false;
}

multiset<int> PokerHand::ConvertToNumber(const char* pokerhand)
{
    multiset<int> num_poker;
    for (unsigned int i = 0; i < 14; i += 3) {
        if (pokerhand[i] >= '2' && pokerhand[i] <= '9') {
            num_poker.insert(pokerhand[i] - '0');
            continue;
        }
        switch (pokerhand[i]) {
        case 'A':
        case 'a':
            num_poker.insert(POKER_A);
            break;
        case 'T':
        case 't':
            num_poker.insert(POKER_T);
            break;
        case 'J':
        case 'j':
            num_poker.insert(POKER_J);
            break;
        case 'Q':
        case 'q':
            num_poker.insert(POKER_Q);
            break;
        case 'K':
        case 'k':
            num_poker.insert(POKER_K);
            break;
        default:
            break;
        }
    }

    return num_poker;
}

PokerHand::PokerHand(const char* pokerhand)
{
    bool is_flush = false;
    //判断花色
    if ((*(pokerhand + 1) == *(pokerhand + 4))
        && (*(pokerhand + 1) == *(pokerhand + 7))
        && (*(pokerhand + 1) == *(pokerhand + 10))
        && (*(pokerhand + 1) == *(pokerhand + 13))) {
        is_flush = true;
    }

    multiset<int> poker = ConvertToNumber(pokerhand);

    map<int, int> map_poker;
    for (auto val : poker) {
        if (map_poker.find(val) == map_poker.end()) {
            map_poker.insert(std::make_pair(val, 1));
        } else {
            map_poker[val]++;
        }
    }

    int max_card_occur = 1; //出现次数最多的牌的次数
    for (auto val : map_poker) {
        if (val.second > max_card_occur)
            max_card_occur = val.second;
    }

    switch (map_poker.size()) {
    case 5: {
        bool is_straight = IsStraight(poker);
        if (is_flush && is_straight) {
            m_poker_type = kPokerType::straight_flush;
        } else if (is_flush) {
            m_poker_type = kPokerType::flush;
        } else if (is_straight) {
            m_poker_type = kPokerType::straight;
        } else {
            m_poker_type = kPokerType::nothing;
        }
        for (auto val : map_poker) {
            m_poker.push_back(val.first);
        }
    } break;
    case 4: {
        m_poker_type = kPokerType::pair;
        m_poker = vector<int>(1);
        m_poker[0] = 0; //为对子占个位置
        for (auto val : map_poker) {
            if (val.second != 2) {
                m_poker.push_back(val.first);
            } else {
                m_poker[0] = val.first;
            }
        }
    } break;
    case 3: {
        if (2 == max_card_occur) {
            m_poker_type = kPokerType::two_pair;
            m_poker = vector<int>{ 0, 0, 0 };
            for (auto val : map_poker) {
                if (2 == val.second) {
                    if (m_poker[1] == 0) {
                        m_poker[1] = val.first;
                    } else {
                        m_poker[0] = val.first;
                    }
                } else {
                    m_poker[2] = val.first;
                }
            }
        } else {
            m_poker_type = kPokerType::three_of_a_kind;
            m_poker = vector<int>{ 0, 0, 0 };
            for (auto val : map_poker) {
                if (3 == val.second) {
                    m_poker[0] = val.first;
                } else {
                    if (0 == m_poker[1]) {
                        m_poker[1] = val.first;
                    } else {
                        m_poker[2] = val.first;
                    }
                }
            }
        }
    } break;
    case 2: {
        map<int, int>::iterator it_begin = map_poker.begin();
        if (max_card_occur == 4) {
            m_poker_type = kPokerType::four_of_a_kind;
            m_poker = vector<int>(2);
            for (auto val : map_poker) {
                if (4 == val.second) {
                    m_poker[0] = val.first;
                } else {
                    m_poker[1] = val.first;
                }
            }
        } else {
            m_poker_type = kPokerType::full_house;
            m_poker = vector<int>(2);
            for (auto val : map_poker) {
                if (3 == val.second) {
                    m_poker[0] = val.first;
                } else {
                    m_poker[1] = val.first;
                }
            }
        }
    } break;
    default:
        break;
    }
}

Result compare(const PokerHand& player, const PokerHand& opponent)
{
    Result compare_result;
    if (player.m_poker_type == opponent.m_poker_type) {
        switch (player.m_poker_type) {
        case straight_flush:
            compare_result = compare_straight_flush(player, opponent);
            break;

        case four_of_a_kind:
            compare_result = compare_four_of_a_kind(player, opponent);
            break;

        case full_house:
            compare_result = compare_full_house(player, opponent);
            break;
        case flush:
            compare_result = compare_flush(player, opponent);
            break;
        case straight:
            compare_result = compare_straight(player, opponent);
            break;
        case three_of_a_kind:
            compare_result = compare_three_of_a_kind(player, opponent);
            break;
        case two_pair:
            compare_result = compare_two_pair(player, opponent);
            break;
        case pair:
            compare_result = compare_pair(player, opponent);
            break;
        case nothing:
            compare_result = compare_nothing(player, opponent);
            break;
        default:
            break;
        }
    } else if (player.m_poker_type > opponent.m_poker_type) {
        compare_result = Result::Loss;
    } else {
        compare_result = Result::Win;
    }

    return compare_result;
}

Result compare_straight(const PokerHand& player, const PokerHand& opponent)
{
    if (player.m_poker[2] > opponent.m_poker[2]) {
        return Result::Win;
    } else if (player.m_poker[2] < opponent.m_poker[2]) {
        return Result::Loss;
    }

    //be care for that  2 3 4 5 6 > 2 3 4 5 14!!!
    if (player.m_poker[4] == opponent.m_poker[4]) {
        return Result::Tie;
    } else if (player.m_poker[2] > opponent.m_poker[2]) {
        return Result::Loss;
    } else {
        return Result::Win;
    }
}

Result compare_straight_flush(const PokerHand& player, const PokerHand& opponent)
{
    return compare_straight(player, opponent);
}

Result compare_three_of_a_kind(const PokerHand& player, const PokerHand& opponent)
{
    if (player.m_poker[0] > opponent.m_poker[0])
        return Result::Win;
    else if (player.m_poker[0] < opponent.m_poker[0])
        return Result::Loss;

    for (unsigned int i = 2; i >= 1; --i) {
        if (player.m_poker[i] > opponent.m_poker[i])
            return Result::Win;
        else if (player.m_poker[i] < opponent.m_poker[i])
            return Result::Loss;
    }

    return Result::Tie;
}

Result compare_four_of_a_kind(const PokerHand& player, const PokerHand& opponent)
{
    for (unsigned int i = 0; i < 2; ++i) {
        if (player.m_poker[i] > opponent.m_poker[i])
            return Result::Win;
        else if (player.m_poker[i] < opponent.m_poker[i])
            return Result::Loss;
    }

    return Result::Tie;
}

Result compare_full_house(const PokerHand& player, const PokerHand& opponent)
{
    return compare_four_of_a_kind(player, opponent);
}

Result compare_nothing(const PokerHand& player, const PokerHand& opponent)
{
    for (int i = POKER_NUM - 1; i >= 0; --i) {
        if (player.m_poker[i] > opponent.m_poker[i]) {
            return Result::Win;
        } else if (player.m_poker[i] < opponent.m_poker[i]) {
            return Result::Loss;
        }
    }
    return Result::Tie;
}

Result compare_flush(const PokerHand& player, const PokerHand& opponent)
{
    return compare_nothing(player, opponent);
}

Result compare_two_pair(const PokerHand& player, const PokerHand& opponent)
{
    for (int i = 0; i <= 2; ++i) {
        if (player.m_poker[i] > opponent.m_poker[i]) {
            return Result::Win;
        } else if (player.m_poker[i] < opponent.m_poker[i]) {
            return Result::Loss;
        }
    }
    return Result::Tie;
}

Result compare_pair(const PokerHand& player, const PokerHand& opponent)
{
    if (player.m_poker[0] > opponent.m_poker[0]) {
        return Result::Win;
    } else if (player.m_poker[0] < opponent.m_poker[0]) {
        return Result::Loss;
    }

    for (unsigned int i = 3; i >= 1; --i) {
        if (player.m_poker[i] > opponent.m_poker[i]) {
            return Result::Win;
        } else if (player.m_poker[i] < opponent.m_poker[i]) {
            return Result::Loss;
        }
    }
    return Result::Tie;
}
