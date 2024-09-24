#include "Player.h"

Player::Player() :attack(0), defense(0) {}

void Player::equipItem(Item& item)
{
    // 장착해야 하는데 이미 장착이 되어있는 경우라면? 함수종료
    if (isItemEquipped(item)) {
        cout << "해당 아이템은 장착이 되어 있다\n";
        return;
    }

    // 장착
    equippedItems.push_back(item);
    // 장착한 아이템으로 변경
    item.setEquipped(true);
    // 공격력
    attack += item.getAttack();
    // 방어력
    defense += item.getDefense();
    // 아이템 장착 출력
    cout << item.getName() << "(" << item.getType() << ") 아이템 장착\n";
}

void Player::UnEquipItem(Item& item)
{
    // 반복자로 벡터 돌면서
    for (auto it = equippedItems.begin(); it != equippedItems.end(); ++it) {
        // 찾으려고 하는 아이템이 아이템의 이름과 동일하면(찾으면)
        if ((*it).getName() == item.getName()) {
            // 공격력 빼고
            attack -= (*it).getAttack();
            // 방어력 빼고
            defense -= (*it).getDefense();
            // 장착해제로 바꾸고
            (*it).setEquipped(false);
            // 벡터에서 제거
            equippedItems.erase(it);
            // 아이템 탈착 출력
            cout << item.getName() << "(" << item.getType() << ") 아이템 탈착\n";
            return;
        }
    }// end of for(it)
    cout << item.getName() << "(" << item.getType() << ") 아이템이 장착되어 있지 않다\n";
}

void Player::displayEquippedItems() const
{
    // 비어 있으면
    if (equippedItems.empty()) {
        cout << "장착된 아이템 없음\n";
        return;
    }
    cout << "==== 장착된 아이템 목록 ====\n";

    // 돌면서 출력
    for (const auto& item : equippedItems) {
        cout << item.getName() << "(" << item.getType() << ") = 공격력 : " << item.getAttack() << ", 방어력 : " << item.getDefense() << "\n";

        // 장착되어 있으면
        if (item.isEquipped()) {
            cout << "-장착중-";
        }
        cout << "\n";
    }
}

// 사용 가능한 아이템 출력
void Player::displayAvailableItems(const vector<Item>& availableItems) const
{
    if (availableItems.empty()) {
        cout << "사용 가능한 아이템 없음\n";
    }
    cout << "==== 사용 가능한 아이템 목록 ====\n";

    for (int i = 0; i < availableItems.size(); ++i) {
        const Item& item = availableItems[i];

        cout << i + 1 << ". " << item.getName() << "(" << item.getType() << ") = 공격력 : " << item.getAttack() << ", 방어력 : " << item.getDefense();

        // 장착중이면
        if (isItemEquipped(item)) {
            cout << "-장착중-";
        }
        cout << "\n";
    }
}

bool Player::isItemEquipped(const Item& item) const
{
    for (const auto& equippeditem : equippedItems) {
        if (equippeditem.getName() == item.getName()) {
            return true;
        }
    }
    return false;
}