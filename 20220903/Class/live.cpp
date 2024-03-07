#include <string>

class Fruit {
    std::string color;
    int a;
    Fruit (std::string _color="red", int _a = 0) {
        color = _color;
        a = _a;
    }
    void teste(){
        std::cout << "おいしい" << std::endl;
    }
    static void color()
};

int main() {
    Fruit fruit_a("blue");
}
