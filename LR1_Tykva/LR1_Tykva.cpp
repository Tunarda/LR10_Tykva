// ������ #5
#include "pch.h"

using namespace System;

int main(array<System::String^>^ args)
{
    Console::WriteLine("Select task:");
    Console::WriteLine("1: Remove all 'abcd' groups from the string.");
    Console::WriteLine("2: Split a sentence into three phrases.");

    int choice = Int32::Parse(Console::ReadLine());

    switch (choice)
    {
        // �������� 1: ������� ����� ������i�. �������� � ����� ��i ����� �i��� ���� �abcd�.
    case 1:
    {
        Console::WriteLine("Enter a string:");
        String^ input = Console::ReadLine();
        String^ result = input->Replace("abcd", "");
        Console::WriteLine("Modified string: {0}", result);
        break;
    }
    // �������� 2: ���� ������, ��������� �� ���� ����. ������ ����� ������������� ������. ������� �� ����� ������ ����� � ����� �������.
    case 2:
    {
        Console::WriteLine("Enter a sentence with three phrases (each ending with a dot):");
        String^ input = Console::ReadLine();
        array<String^>^ phrases = input->Split('.');

        for each (String ^ phrase in phrases)
        {
            if (!String::IsNullOrWhiteSpace(phrase))
            {
                Console::WriteLine(phrase->Trim() + ".");
            }
        }
        break;
    }

    default:
        Console::WriteLine("Invalid choice. Please select 1 or 2.");
        break;
    }
    Console::WriteLine("");
    Console::ReadLine();
    return 0;
}
