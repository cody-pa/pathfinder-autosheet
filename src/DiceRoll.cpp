#include "DiceRoll.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

//////////////////////////////////////////////////////////
/// Input params: A string containing user input.      ///
/// Preconditions: input contains a valid roll string. ///
/// Returns: result of roll                            ///
//////////////////////////////////////////////////////////
Result<int> DiceRoll::roll(std::string input)
{
    unsigned int pcount = 0;
    unsigned int pdie_size=0;
    int pmodifier = 0;
    string buffer = "";
    size_t i;

    // Get first set of numbers
    for (i = 0; i < input.size(); ++i)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            buffer += input[i];
        }
        else {
            break;
        }
    }
    // Try to parse the first number
    try
    {
        pcount = stoi(buffer);
    }
    catch(std::invalid_argument& e)
    {
        return Result<int>();
    }
    
    // Parsed without errors
    buffer = "";
    if (pcount == 0)
    {
        return Result<int>();
    }
    // Parsed successfully; try moving on
    else if (i < input.size() && input[i] == 'd')
    {
        // Parse next set of numbers... the count
        ++i;
        for (; i < input.size(); ++i)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                buffer += input[i];
            }
            else {
                break;
            }
        }
        // Attempt to parse string
        try
        {
            pdie_size = stoi(buffer);
        }
        catch(std::invalid_argument& e)
        {
            cout << "died on second stoi" << endl;
            return Result<int>();
        }
        // successfully parsed
        if (pdie_size == 0)
        {
            return Result<int>();
        }

        // successfully got count, move on to parse modifier
        buffer = "";
        // skip spaces
        while (input[i] == ' ' && i < input.size())
            ++i;
        
        if (i < input.size() && (input[i] == '+' || input[i] == '-'))
        {
            char symbol = input[i];
            ++i;

            // skipp more spaces
            while (input[i] == ' ' && i < input.size())
                ++i;
            for(; i<input.size(); ++i)
            {
                if (input[i] >= '0' && input[i] <= '9')
                {
                    buffer += input[i];
                }
                else {
                    break;
                }
            }
            try
            {
                pmodifier = stoi(buffer);
            }
            catch(std::invalid_argument& e)
            {
                return Result<int>();
            }
            // successful parse
            if (pmodifier != 0)
            {
                if (symbol == '-')
                {
                    pmodifier *= -1;
                }
            }
        }
    }
    // did not find d after first set of numbers
    else
    {
        return Result<int>();
    }


    count = pcount;
    die_size = pdie_size;
    modifier = pmodifier;

    last_result = Result<int>(perform_roll());
    return last_result;
}

///////////////////////////////////////////////////////
/// Preconditions: roll fields properly initialized ///
/// Returns: result of roll                         ///
///////////////////////////////////////////////////////
int DiceRoll::perform_roll()
{
    cout << count << "d" << die_size;
    if (modifier > 0)
    {
        cout << " + " << modifier;
    }
    else if (modifier < 0)
    {
        cout << " - " << modifier*-1;
    }

    cout << " = ";

    int sum = 0;
    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int r = RANDOM_RANGE(1, die_size);
        sum += r;
        cout << r;
        if (i < count-1)
        {
            cout << " + ";
        }
    }
    
    if (modifier > 0)
    {
        cout << " + " << modifier;
    }
    else if (modifier < 0)
    {
        cout << " - " << modifier*-1;
    }

    cout << " = " << sum << endl;
    return sum;
}

///////////////////////////////////////////////////////
/// This function just rolls with already-set data. ///
///////////////////////////////////////////////////////
Result<int> DiceRoll::roll()
{
    if (ready)
    {
        return Result<int>(perform_roll());
    }
    else
        return Result<int>();
}

DiceRoll::DiceRoll()
{
    count = 0;
    die_size = 0;
    modifier = 0;
    last_result = Result<int>();
    ready = false;
}

DiceRoll::DiceRoll(unsigned int p_count, unsigned int p_die_size, int p_modifier)
{
    count = p_count;
    die_size = p_die_size;
    modifier = p_modifier;
    last_result = Result<int>();

    ready = true;
}
