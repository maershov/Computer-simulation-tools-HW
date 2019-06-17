
#include <iostream>
#include <math.h>
#include <vector>

#define ALFA 0.01;
#define V_C 0;
#define  KZERO 0.0003;
#define R0 1;
#define  U 1;
#define DX 1;
#define DY 1;

using namespace std;
using std::vector;

class T_GRID{
public:

    T_GRID(){

    }

    T_GRID(int number, float value, float wall_value): main_grid(number), grids_number(number){
        for (vector<float>& i : main_grid){
            i.assign(number, value);
        }
        for (int i = 0; i < number; ++i){
            main_grid[number - 1][i] = wall_value;
        }

    }

    float delta_counter(T_GRID some_grid){
        float delta = 0;
        float buf_out = 0;

        for (int i = 1; i < grids_number - 1; ++i)
        {
            for (int j = 1; j < grids_number - 1; ++j)
            {
                delta = abs(some_grid.get_grid() [i][j] - main_grid[i][j]);
                if (delta > buf_out)
                    buf_out = delta;
            }
        }
        return buf_out;
    }

    void change_grid(T_GRID some_grid){
        for (int i = 0; i < grids_number; ++i){
            for (int j = 0; j < grids_number; ++j){
                main_grid[i][j] = some_grid.get_grid()[i][j];
            }
            main_grid[i][grids_number - 1] = main_grid[i][grids_number - 2];
        }
    }

    void change_grid_vec(vector<vector<float> > some_grid){
        for (int i = 0; i < grids_number; ++i){
            for (int j = 0; j < grids_number; ++j){
                main_grid[i][j] = some_grid[i][j];
            }
            main_grid[i][grids_number - 1] = main_grid[i][grids_number - 2];
        }
    }

    void print_grid(){
        for (int i = 0; i < main_grid.size(); ++i){
            for (int j = 0; j < main_grid[i].size(); ++j){
                cout << main_grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int get_grids_number() const {
        return grids_number;
    }

    vector<vector<float> > get_grid() const {
        return main_grid;
    }
private:

    vector<vector<float> > main_grid;
    int grids_number;
};


class MAIN_GRID : public T_GRID{

public:
    MAIN_GRID(int number, float value, float wall_value): main_grid(number), grids(number), k(grids), ke(grids), ks(grids), kw(grids), kn(grids), Pe(grids),
                                                          Ps(grids), Pw(grids), Pn(grids),AE(grids),
                                                          AS(grids), AW(grids), AN(grids), Sc(grids), Sp(grids), b(grids), AP(grids){
        for (vector<float>& i : k){
            i.assign(number, 0);
        }
        for (vector<float>& i : ke){
            i.assign(number, 0);
        }
        for (vector<float>& i : kw){
            i.assign(number, 0);
        }
        for (vector<float>& i : ks){
            i.assign(number, 0);
        }
        for (vector<float>& i : kn){
            i.assign(number, 0);
        }
        for (vector<float>& i : Pe){
            i.assign(number, 0);
        }
        for (vector<float>& i : Pw){
            i.assign(number, 0);
        }
        for (vector<float>& i : Ps){
            i.assign(number, 0);
        }
        for (vector<float>& i : Pn){
            i.assign(number, 0);
        }
        for (vector<float>& i : AE){
            i.assign(number, 0);
        }
        for (vector<float>& i : AW){
            i.assign(number, 0);
        }
        for (vector<float>& i :AS){
            i.assign(number, 0);
        }
        for (vector<float>& i : AN){
            i.assign(number, 0);
        }
        for (vector<float>& i :Sc){
            i.assign(number, 0);
        }
        for (vector<float>& i : Sp){
            i.assign(number, 0);
        }
        for (vector<float>& i :b){
            i.assign(number, 0);
        }
        for (vector<float>& i : AP){
            i.assign(number, 0);
        }

        for (vector<float>& i : main_grid){
            i.assign(grids, 300);
        }


        for (int i = 0; i < number; ++i){
            main_grid[number - 1][i] = wall_value;
        }

    }

    MAIN_GRID(const T_GRID* t_grid): grids(t_grid->get_grids_number()), main_grid(grids), k(grids), ke(grids), ks(grids), kw(grids), kn(grids), Pe(grids),
                                                                        Ps(grids), Pw(grids), Pn(grids),AE(grids),
                                                                          AS(grids), AW(grids), AN(grids), Sc(grids), Sp(grids), b(grids), AP(grids){
        for (vector<float>& i : k){
            i.assign(grids, 0);
        }
        for (vector<float>& i : ke){
            i.assign(grids, 0);
        }
        for (vector<float>& i : kw){
            i.assign(grids, 0);
        }
        for (vector<float>& i : ks){
            i.assign(grids, 0);
        }
        for (vector<float>& i : kn){
            i.assign(grids, 0);
        }
        for (vector<float>& i : Pn){
            i.assign(grids, 0);
        }
        for (vector<float>& i : Pe){
            i.assign(grids, 0);
        }
        for (vector<float>& i : Pw){
            i.assign(grids, 0);
        }
        for (vector<float>& i : Ps){
            i.assign(grids, 0);
        }
        for (vector<float>& i : AE){
            i.assign(grids, 0);
        }
        for (vector<float>& i : AW){
            i.assign(grids, 0);
        }
        for (vector<float>& i :AS){
            i.assign(grids, 0);
        }
        for (vector<float>& i : AN){
            i.assign(grids, 0);
        }
        for (vector<float>& i :Sc){
            i.assign(grids, 0);
        }
        for (vector<float>& i : Sp){
            i.assign(grids, 0);
        }
        for (vector<float>& i :b){
            i.assign(grids, 0);
        }
        for (vector<float>& i : AP){
            i.assign(grids, 0);
        }



        for (vector<float>& i : main_grid){
            i.assign(grids, 0);
        }

        for (int i = 0; i < grids; ++i){
            for (int j = 0; j < grids; ++j){
                main_grid[i][j] = t_grid->get_grid()[i][j];
            }
        }

    }

    void print_grid(){

        for (int i = 0; i < main_grid.size(); ++i){
            for (int j = 0; j < main_grid[i].size(); ++j){
                cout << main_grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<vector<float> > get_grid(){
        return main_grid;
    }

    int get_grind_number(){
        return grids;
    }

    void k_counter(T_GRID some_grid){


        for (int i = 0; i < grids; ++i)
        {
            for (int j = 0; j < grids; ++j){
                k[i][j] = some_grid.get_grid()[i][j] / 400 +alfa;
                }
        }


    }

    void coefficients_counter(T_GRID some_grid){

        for (int i = 1; i < grids - 1; ++i)
        {
            for (int j = 1; j < grids - 1; ++j)
            {
                k [0][j] = k [1][j];
                k [grids - 1][j] = k [grids - 2][j];
                k [i][grids - 1] = k [i][grids - 2];
                ke [i][j] = 2*k[i][j+1]*k[i][j]/(k[i][j+1]+k[i][j]);
                kw [i][j] = 2*k[i][j-1]*k[i][j]/(k[i][j-1]+k[i][j]);
                ks [i][j] = 2*k[i+1][j]*k[i][j]/(k[i+1][j]+k[i][j]);
                kn [i][j] = 2*k[i-1][j]*k[i][j]/(k[i-1][j]+k[i][j]);
                Pe [i][j] = ro*u*dx/ke[i][j];
                Pw [i][j] = ro*u*dx/kw[i][j];
                Ps [i][j] = ro*v*dy/ks[i][j];
                Pn [i][j] = ro*v*dy/kn[i][j];
                Sc [i][j] = 0;
                Sp [i][j] = 0;

                if (Pw [i][j]<-10) AW [i][j]=Pw [i][j]*kw [i][j]/dx;
                else if (Pw [i][j]==-10 || (Pw [i][j]>-10 && Pw [i][j]<0))
                    AW [i][j]=(pow((1+0.1*Pw [i][j]),5)+Pw [i][j])*kw [i][j]/dx;
                else if (Pw [i][j]==0 || (Pw [i][j]>0 && Pw [i][j]<10) || Pw [i][j]==10)
                    AW [i][j]=pow((1-0.1*Pw [i][j]),5)*kw [i][j]/dx;
                else AW [i][j]=0;

                if (Pe [i][j]<-10) AE [i][j]=-Pe [i][j]*ke [i][j]/dx;
                else if (Pe [i][j]==-10 || (Pe [i][j]>-10 && Pe [i][j]<0))
                    AE [i][j]=(pow((1+0.1*Pe [i][j]),5)-Pe [i][j])*ke [i][j]/dx;
                else if (Pe [i][j]==0 || (Pe [i][j]>0 && Pe [i][j]<10) || Pe [i][j]==10)
                    AE [i][j]=pow((1-0.1*Pe [i][j]),5)*ke [i][j]/dx;
                else AE [i][j]=0;

                if (Ps [i][j]<-10) AS [i][j]=Ps [i][j]*ks [i][j]/dy;
                else if (Ps [i][j]==-10 || (Ps [i][j]>-10 && Ps [i][j]<0))
                    AS [i][j]=(pow((1+0.1*Ps [i][j]),5)+Ps [i][j])*ks [i][j]/dy;
                else if (Ps [i][j]==0 || (Ps [i][j]>0 && Ps [i][j]<10) || Ps [i][j]==10)
                    AS [i][j]=pow((1-0.1*Ps [i][j]),5)*ks [i][j]/dy;
                else AS [i][j]=0;

                if (Pn [i][j]<-10) AN [i][j]=-Pn [i][j]*kn [i][j]/dy;
                else if (Pn [i][j]==-10 || (Pn [i][j]>-10 && Pn [i][j]<0))
                    AN [i][j]=(pow((1+0.1*Pn [i][j]),5)-Pn [i][j])*kn [i][j]/dy;
                else if (Pn [i][j]==0 || (Pn [i][j]>0 && Pn [i][j]<10) || Pn [i][j]==10)
                    AN [i][j]=pow((1-0.1*Pn [i][j]),5)*kn [i][j]/dy;
                else AN [i][j]=0;

                b[i][j] = -K0*(some_grid.get_grid()[i][j]-300)*(some_grid.get_grid()[i][j]-300);
                AP [i][j] = AE [i][j] + AW [i][j] + AS [i][j] + AN [i][j] - Sp [i][j]*dx*dy;
            }
        }

    }

    float T_counter(T_GRID some_grid){
        float buffer = 0;
        float buffer_inner = 0;

        for (int i = 1; i < grids - 1; ++i)
        {
            for (int j = 1; j < grids - 1; ++j)
            {
                main_grid [i][j] = (AE [i][j]*some_grid.get_grid() [i][j+1]+ AW [i][j]*some_grid.get_grid() [i][j-1] + AS [i][j]*some_grid.get_grid() [i+1][j]+ AN [i][j]*some_grid.get_grid() [i-1][j] + b [i][j])/AP [i][j];
                buffer = abs(some_grid.get_grid() [i][j] - main_grid [i][j]);
                if (buffer > buffer_inner)
                    buffer_inner = buffer;
            }
        }
        return buffer_inner;
    }




private:

    int v = V_C;
    float K0 = KZERO;
    int ro = R0;
    int u = U;
    int dx = DX;
    int dy = DY;
    float alfa = ALFA;
    int grids;
    vector<vector<float> > main_grid;
    vector<vector<float> > k;
    vector<vector<float> > kw;
    vector<vector<float> > ks;
    vector<vector<float> > kn;
    vector<vector<float> > ke;
    vector<vector<float> > Pw;
    vector<vector<float> > Ps;
    vector<vector<float> > Pn;
    vector<vector<float> > Pe;
    vector<vector<float> > Sc;
    vector<vector<float> > Sp;
    vector<vector<float> > AE;
    vector<vector<float> > AW;
    vector<vector<float> > AS;
    vector<vector<float> > AN;
    vector<vector<float> > b;
    vector<vector<float> > AP;

};



int main()
{
    float   min_value_inner, min_value, buffer_inner, buffer_out;

    min_value_inner = 1;
    min_value = 1;
    buffer_inner = 0;
    buffer_out = 0;

    cout.precision(4); //ограничение знаков
    cout << fixed;

    T_GRID Tzero(10, 300, 400);
    T_GRID Tprev(10, 300, 400);
    T_GRID Td(10, 0, 0);
    T_GRID Td1(10, 0, 0);
    MAIN_GRID main_grid(10, 300, 400);

    cout << "INITIAL GRID:" << endl;
    main_grid.print_grid();
    cout << endl;





    while (min_value > 0.001)
    {

        main_grid.k_counter(Tzero);
        Tprev.change_grid(Tzero);

        main_grid.coefficients_counter(Tzero);


        while (min_value_inner > 0.001)
        {
            buffer_inner = main_grid.T_counter(Tzero);
            Tzero.change_grid_vec(main_grid.get_grid());
            min_value_inner = buffer_inner;

        }
        min_value_inner = 1;
        buffer_out = Tzero.delta_counter(Tprev);
        min_value = buffer_out;

    }



    cout << "FINAL GRID:" << endl;
    Tzero.print_grid();
    cout << endl;


}


////////result
/*
INITIAL GRID:
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000

FINAL GRID:
300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000 300.0000
300.0000 302.7297 305.0241 306.7508 307.9533 308.7430 309.2335 309.5131 309.6391 309.6391
300.0000 305.6469 310.2857 313.6993 316.0325 317.5430 318.4715 318.9971 319.2331 319.2331
300.0000 308.9742 316.0644 321.0844 324.4079 326.5078 327.7762 328.4859 328.8023 328.8023
300.0000 313.0556 322.7752 329.2773 333.3901 335.9016 337.3822 338.1975 338.5577 338.5577
300.0000 318.4598 330.9938 338.7266 343.3254 346.0115 347.5473 348.3765 348.7388 348.7388
300.0000 326.2207 341.5430 349.9671 354.5868 357.1409 358.5495 359.2932 359.6141 359.6141
300.0000 338.3703 355.5772 363.5868 367.5452 369.5975 370.6863 371.2480 371.4877 371.4877
300.0000 359.1766 374.5182 380.0862 382.5064 383.6798 384.2804 384.5844 384.7128 384.7128
400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000 400.0000


Process finished with exit code 0


*/


