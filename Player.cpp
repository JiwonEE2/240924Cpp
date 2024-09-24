#include "Player.h"

Player::Player() :attack(0), defense(0) {}

void Player::equipItem(Item& item)
{
    // �����ؾ� �ϴµ� �̹� ������ �Ǿ��ִ� �����? �Լ�����
    if (isItemEquipped(item)) {
        cout << "�ش� �������� ������ �Ǿ� �ִ�\n";
        return;
    }

    // ����
    equippedItems.push_back(item);
    // ������ ���������� ����
    item.setEquipped(true);
    // ���ݷ�
    attack += item.getAttack();
    // ����
    defense += item.getDefense();
    // ������ ���� ���
    cout << item.getName() << "(" << item.getType() << ") ������ ����\n";
}

void Player::UnEquipItem(Item& item)
{
    // �ݺ��ڷ� ���� ���鼭
    for (auto it = equippedItems.begin(); it != equippedItems.end(); ++it) {
        // ã������ �ϴ� �������� �������� �̸��� �����ϸ�(ã����)
        if ((*it).getName() == item.getName()) {
            // ���ݷ� ����
            attack -= (*it).getAttack();
            // ���� ����
            defense -= (*it).getDefense();
            // ���������� �ٲٰ�
            (*it).setEquipped(false);
            // ���Ϳ��� ����
            equippedItems.erase(it);
            // ������ Ż�� ���
            cout << item.getName() << "(" << item.getType() << ") ������ Ż��\n";
            return;
        }
    }// end of for(it)
    cout << item.getName() << "(" << item.getType() << ") �������� �����Ǿ� ���� �ʴ�\n";
}

void Player::displayEquippedItems() const
{
    // ��� ������
    if (equippedItems.empty()) {
        cout << "������ ������ ����\n";
        return;
    }
    cout << "==== ������ ������ ��� ====\n";

    // ���鼭 ���
    for (const auto& item : equippedItems) {
        cout << item.getName() << "(" << item.getType() << ") = ���ݷ� : " << item.getAttack() << ", ���� : " << item.getDefense() << "\n";

        // �����Ǿ� ������
        if (item.isEquipped()) {
            cout << "-������-";
        }
        cout << "\n";
    }
}

// ��� ������ ������ ���
void Player::displayAvailableItems(const vector<Item>& availableItems) const
{
    if (availableItems.empty()) {
        cout << "��� ������ ������ ����\n";
    }
    cout << "==== ��� ������ ������ ��� ====\n";

    for (int i = 0; i < availableItems.size(); ++i) {
        const Item& item = availableItems[i];

        cout << i + 1 << ". " << item.getName() << "(" << item.getType() << ") = ���ݷ� : " << item.getAttack() << ", ���� : " << item.getDefense();

        // �������̸�
        if (isItemEquipped(item)) {
            cout << "-������-";
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