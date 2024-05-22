#include <iostream>

class Car
{
protected:
    float kecepatan;
    float bensin;
    float bensin_max;
    int penumpang;
public:
    Car()
    {
        kecepatan = 10;
        bensin = 100;
        bensin_max = 100;
        penumpang = 4;
    }
    Car(float Kecepatan, float Bensin)
    {
        kecepatan = Kecepatan;
        bensin = Bensin;
        bensin_max = 100;
        penumpang = 4;
    }
    
    virtual void jalan()
    {
        bensin -= kecepatan;
        std::cout<< "mobil ini berjalan sejauh "<<kecepatan<<" km/jam"<<std::endl;
    }
};

class SuperCar : public Car
{
    public:
    SuperCar() : Car()
    {
        kecepatan = 100;
        bensin = 1000;
        bensin_max = 1000;
    }
    SuperCar(float Bensin, float Kecepatan) : Car(Bensin, Kecepatan)
    {
        bensin_max = 1000;
    }
    
    void displayBensin()
    {
        std::cout<<"bensin: "<<bensin<<std::endl;
    }
};

class Pickup : public Car
{
    private:
    float kapasitas;
    float kapasitas_max;
    float current_kecepatan;
    
    public:
    Pickup() : Car()
    {
        kapasitas_max = 100;
        kapasitas = 1;
        current_kecepatan = kecepatan;
    }
    
    void angkut(float berat_barang)
    {
        if(kapasitas + berat_barang < kapasitas_max)
        {
            kapasitas += berat_barang;
            current_kecepatan = kecepatan/kapasitas;
            std::cout<<"berhasil di pickup, kapasitas sekarang adalah: "<<kapasitas<<" Kg\n";
            return;
        }
        std::cout<<"Kapasitas tidak memadai!\n";
    }
    
    void jalan() override
    {
        bensin -= kecepatan+kapasitas;
        std::cout<<"mobil ini berjalan sejauh "<<current_kecepatan<<" km/jam dengan kapasitas terpakai "<<kapasitas<<" Kg"<<std::endl;
    }
};

int main()
{
    Car mobil;
    SuperCar mobilSuper;
    Pickup pikep;
    
    mobil.jalan();
    mobilSuper.jalan();
    pikep.angkut(2);
    pikep.jalan();
    
    SuperCar mobilku(5000, 500);
    mobilku.displayBensin();
    mobilku.jalan();
    

    return 0;
}
