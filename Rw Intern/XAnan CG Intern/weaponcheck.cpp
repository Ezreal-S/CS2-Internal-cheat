#include "mem Aimbot.h"
#include "imgui/imgui.h"
#include <unordered_set>
#include <iostream>

bool weaponcheck()
{
    Player LocalPlayer{};
    LocalPlayer.control = Address::GetLocalPlayerControl();
    LocalPlayer.pawn = Get::PlayerPawnAddress(LocalPlayer.control);

    std::string weaponName = Get::GetWeaponName(LocalPlayer.pawn);

    // ʹ�ü��ϴ洢���������������
    static const std::unordered_set<std::string> restrictedWeapons = {
        "molotov", "incgrenade", "decoy",
        "flashbang", "hegrenade", "smokegrenade",
        "knife", "c4","taser"
    };

    // ��鵱ǰ�����Ƿ��������б���
    if (restrictedWeapons.find(weaponName) != restrictedWeapons.end())
    {
        return false; // ���������
    }

    return true; // �������
}
