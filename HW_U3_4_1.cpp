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

    void Sort(Adress* obj, size_t size);
    void swop(Adress& obj1, Adress& obj2);

    friend std::ostream& operator << (std::ofstream& os, const Adress& obj)
    {
        os << obj.city << ", " << obj.street << ", " << obj.Num_home << ", " << obj.apart << std::endl; return os;
    }

    friend bool operator > (Adress obj1, Adress obj2) { return (obj1.city > obj2.city) ? true : false; }

    ~Adress() { /*std::cout << "Obj delete" << std::endl;*/ }
};
void Adress::swop(Adress& obj1, Adress& obj2) 
{
    Adress buf{};
    buf = obj1;
    obj1 = obj2;
    obj2 = buf; 
}


void Adress::Sort( Adress* obj, size_t size)
{
    // находим минимальный поднимаем наверх swap
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (obj[j] > obj[j + 1])
            {
                swop(obj[j], obj[j + 1]);
            }
        }
    }
}


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
        Adress* obj = new Adress [Num_block];
        outfile << Num_block << std::endl;

        for (int i = 0; i < Num_block;++i)
        {
            getline(inpfile, adress::c_);
            getline(inpfile, adress::s_);
            getline(inpfile, adress::buf);
            adress::h_ = std::stoi(adress::buf);
            getline(inpfile, adress::buf);
            adress::a_ = std::stoi(adress::buf);
            obj[i].setDataAdress(adress::c_, adress::s_, adress::h_, adress::a_);
            //outfile << obj;
        }

        obj[0].Sort(obj, Num_block);
        for (int i = 0; i < Num_block;++i)
        {
            outfile << obj[i];
        }
        //delete[Num_block] ibj;
    }
    catch (...)
    {
        std::cout << "Error converting str -> int";
        inpfile.close();
    }
    return EXIT_SUCCESS;
}


/*
5
Москва
Строителей
34
12
Новокузнецк
Науки
5
16
Омск
Пушкина
2
13
Москва
Арбат
4
1
Новосибирск
Мира
85
64
*/