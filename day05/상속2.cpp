//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Car {
//private:
//    int gasolineGauge;
//public:
//    Car(int ag) : gasolineGauge(ag) {}  // 생성자 정의
//    int getGasGauge() { return gasolineGauge; }
//};
//
//class HybridCar : public Car {
//private:
//    int electricGauge;
//public:
//    HybridCar(int ag, int eg) : Car(ag), electricGauge(eg) {}  //부모 생성자 호출
//    int getElectricGauge() { return electricGauge; }
//};
//
//class HybridWaterCar : public HybridCar {
//private:
//    int waterGauge;
//public:
//    HybridWaterCar(int ag, int eg, int wg) : HybridCar(ag, eg), waterGauge(wg) {}  // 부모 생성자 호출
//    void showCurrentGauge() {
//        cout << "Gasoline: " << getGasGauge() << endl;
//        cout << "Electric: " << getElectricGauge() << endl;
//        cout << "Water: " << waterGauge << endl;
//    }
//};
//
//int main() {
//    HybridWaterCar car(10, 20, 30);  // 올바른 생성자 호출
//    car.showCurrentGauge();
//
//    return 0;
//}
