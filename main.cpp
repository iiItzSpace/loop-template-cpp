#include <algorithm>
#include <cctype>
#include <iostream>
#include <print>
#include <string>
#include <string_view>

namespace
{
std::string NormalizeText(std::string_view text)
{
    auto isSpace = [](const unsigned char ch) { return std::isspace(ch); };

    while (!text.empty() && isSpace(text.front()))
    {
        text.remove_prefix(1);
    }

    while (!text.empty() && isSpace(text.back()))
    {
        text.remove_suffix(1);
    }

    std::string result(text);
    std::ranges::transform(result, result.begin(),
                           [](const unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    return result;
}

bool AskToRepeat()
{
    std::string input;
    while (true)
    {
        std::print("\nRepeat? [Y/n]: ");
        if (!std::getline(std::cin, input))
        {
            return false;
        }

        std::string normalized = NormalizeText(input);
        if (normalized.empty() || normalized == "y" || normalized == "yes")
        {
            return true;
        }

        if (normalized == "n" || normalized == "no")
        {
            return false;
        }

        std::println("Invalid option. Enter 'Y' or 'n'.");
    }
}
} // namespace

int main()
{
    std::println("===================");
    std::println("   Program Title   ");
    std::println("===================");

    do
    {
        std::println("Input: ");
        // Program logic

    } while (AskToRepeat());

    return 0;
}
