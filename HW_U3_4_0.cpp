//+++++++++++++++++++++++++++++++++Adress++++++++++++++++++++++++++++++++++++++//
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Adress
{
private:
    std::string city{};
    std::string street{};
    int Num_home{};
    int apart{};
public:
    Adress() = default;
    Adress(std::string c, std::string s, int h, int a) :city{ c }, street{ s }, Num_home{ h }, apart{ a } {};
    void setDataAdress(std::string c, std::string s, int h, int a)
    {
        city = c;
        street = s;
        Num_home = h;
        apart = a;
    }
    friend std::ostream& operator << (std::ofstream& os, const Adress& obj)
    {
        os << obj.city << ", " << obj.street << ", " << obj.Num_home << ", " << obj.apart << std::endl; return os;
    }
};

namespace adress 
{
    std::string const infile = "C:\\Users\\Tatiana\\source\\repos\\HW_U3_4_1\\HW_U3_4_1\\in.txt";
    std::string const outfile = "C:\\Users\\Tatiana\\source\\repos\\HW_U3_4_1\\HW_U3_4_1\\out.txt";
    std::string buf{};

    std::string c_{}, s_{};
    int h_{}, a_{};
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream inpfile(adress::infile);

    //std::cout << adress::infile;
    try
    {
        if (!inpfile.is_open())
        {
            std::cout << "Error open file";
            return 1;
        }
        
        std::ofstream outfile(adress::outfile);
        if (!outfile.is_open())
        {
            std::cout << "Error open file";
            return 1;
        }

        getline(inpfile, adress::buf);
        int Num_block = std::stoi(adress::buf);
        Adress obj{};
        outfile << Num_block << std::endl;

        for (int i = 0; i < Num_block;++i)
        {
            getline(inpfile, adress::c_);
            getline(inpfile, adress::s_);
            getline(inpfile, adress::buf);
            adress::h_ = std::stoi(adress::buf);
            getline(inpfile, adress::buf);
            adress::a_ = std::stoi(adress::buf);
            obj.setDataAdress(adress::c_, adress::s_, adress::h_, adress::a_);
            outfile << obj;
        }

    }
    catch (...)
    {
        std::cout << "Error converting str -> int";
        inpfile.close();
    }
    return EXIT_SUCCESS;
}
