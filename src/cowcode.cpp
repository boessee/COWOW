/*program that has a cow drawing at the beginning in an existing file 
and every time i love the cow quote i can just add it as a list 
but all previous should be also saved on the first place (one cow drawing is enough tho)*/

#include <iostream>     //for console
#include <fstream>      //for file
#include <string>
//"using namespace std;" can be as well, but better without

int main() 
{
    //checking if file exists and empty/not
    std::ifstream checkFile("cowtext.txt");
    bool fileEmpty = checkFile.peek() == std::ifstream::traits_type::eof();
    checkFile.close();

    //opening file in append aka adding new stuff mode
    std::ofstream file("cowtext.txt", std::ios::app);

    //adding funny cow is file is empty so we can admite it
    if (fileEmpty) {
        file << " -----------------    \n";
        file << "|    WHAT DOES    |   \n";
        file << "|     COW SAY     |   \n";
        file << " -----------------    \n";
        file << "      ^__^            \n";
        file << "      (oo)`_______    \n";
        file << "      (__)(       )~  \n";
        file << "          ||----w |   \n";
        file << "    mou?  ||     ||   \n";
        file << "                      \n\n";
    }

    //finding out what did cow say
    std::string text;
    std::cout << "It is a cow-time, mensch, enter your quote!! ";
    std::getline(std::cin, text);

    //writing new text after the cow and continuing
    file << text << "\n\n";

    file.close();

    std::cout << "New funny cow quote was saved to cowtext.txt" << std::endl;

    return 0;
}
