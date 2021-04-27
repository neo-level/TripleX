#include <iostream>
#include <ctime>


void PrintIntroduction(int Level)
{
    if (Level == 1)
    {
        std::cout
                << "\n\nYou are one of the sole survivors after the nuclear war, the evil cyber brain UpCrux is controlling the world!"
                << "\n";
        std::cout
                << "Finding yourself at the bottom of the tower level: " << Level
                << ", a door opens. In the distance a terminal is standing, waiting for input..."
                << "\n\n";
    } else
    {
        std::cout
                << "You find yourself at tower level: " << Level
                << " walking towards the terminal, it is waiting for input..."
                << "\n\n";
        std::cout
                << "Enter the correct codes to open the door to the next level."
                << "\n";
    }

}

bool PlayGame(int Level, int MaxLevel, int Lives)
{

    PrintIntroduction(Level);

    int CodeA = rand() % Level + Level;
    int CodeB = rand() % Level + Level;
    int CodeC = rand() % Level + Level;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout
            << "+ There are 3 numbers in the code. \n";
    std::cout
            << "+ The codes add up to: " << CodeSum
            << "\n";
    std::cout
            << "+ The codes multiply to give: " << CodeProduct
            << "\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if (Level == MaxLevel)
        {
            std::cout
                    << "Ksshhhhhh..... The final door opens, UpCrux is within your grasp... \n"
                    << "You run as fast as you can towards it core, take your M-12 corrupter and jam it inside its manifestation."
                    << "The last thing you see is a bright light, a countdown heard in the distance and....Boooommmm....";
            return true;
        }

        std::cout
                << "Ksshhhhhh..... The door opens, yet again in the distance a terminal... \n";
        return true;
    } else
    {
        std::cout
                << "The codes you entered are incorrect, you have " << --Lives <<" amount of tries left!!!\n";
        return false;
    }

}

int main()
{
    // Creates a new random sequence based on the time of the day.
    srand(time(NULL));

    int LevelDifficulty = 1;
    int const MaxLevel = 10;
    int Lives = 3;

    while (LevelDifficulty <= MaxLevel && Lives != 0)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxLevel, Lives);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        else
        {
            --Lives;
        }
    }

    std::cout
            << "It's all over, humanity can start rebuilding its life, hopefully this time with a lessons learned approach... ";

    return 0;
}
