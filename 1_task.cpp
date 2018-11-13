#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double maxvalue (double x, double y, double z)
{
	double max;
	if (x >= y && x >= z)
		max = x;
	else if (y >= x && y >= z)
		max = y;
	else if (z >= x && z >= y)
		max = z;
	return max;
}

double minvalue(double x, double y, double z)
{
	double min;
	if (x <= y && x <= z)
		min = x;
	else if (y <= x && y <= z)
		min = y;
	else if (z <= x && z <= y)
		min = z;
	return min;
}

void RGBtoCMY(double R, double G, double B) 
{
	double C, M, Y;
	C = 1 - R;
	M = 1 - G;
	Y = 1 - B;
	cout << "C = " << C << " M = " << M << " Y = " << Y << endl;
}

void RGBtoCMYK(double R, double G, double B)
{
	double C, M, Y, K;
	K = 1 - maxvalue(R, G, B);
	C = (1 - R - K) / (1 - K);
	M = (1 - G - K) / (1 - K);
	Y = (1 - B - K) / (1 - K);
	cout << "C = " << C << " M = " << M << " Y = " << Y <<" K = "<< K << endl;
}

void RGBtoHSV(double R, double G, double B)
{
	double H, S, V, min, max;
	max = maxvalue(R, G, B);
	min = minvalue(R, G, B);
	if (max == min)
		 H = 0;
    else if (max == R && G <= B)
		 H = 60 * (G - B) / (max - min) + 360;
    else if (max == R && G > B)
		 H = 60 * (G - B) / (max - min) ;
	else if (max == G)
		H = 60 * (B - R) / (max - min) + 120;
	else if (max == B)
		H = 60 * (R - G) / (max - min) + 240;
	
	if (max == 0)
		S = 0;
	else
		S = 1 - min / max;
	V = max;
	cout << "H = " << H << " S = " << S << " V = " << V << endl;
}

void RGBtoHSL(double R, double G, double B)
{
	double max, min, H, L, S = 0;
	max = maxvalue(R, G, B);
	min = minvalue(R, G, B);
	if (max == min)
		H = 0;
	else if (max == R && G <= B)
		H = 60 * (G - B) / (max - min) + 360;
	else if (max == R && G > B)
		H = 60 * (G - B) / (max - min);
	else if (max == G)
		H = 60 * (B - R) / (max - min) + 120;
	else if (max == B)
		H = 60 * (R - G) / (max - min) + 240;

	L = (max + min) / 2;

	if (L == 0 || max == min)
		S = 0;
	else if ( L > 0 && L <= 0.5)
		S = (max - min) / (2 * L);
	else if (L > 0.5 && L < 1)
		S = (max - min) / (2 - 2 * L);
	cout << "H = " << H << " S = " << S << " L = " << L << endl;
}

void RGBtoXYZ(double R, double G, double B)
{

	double X, Y, Z;
	double a = 1 / 0.17697;
	X = a * (0.49 + 0.31 + 0.20) * R;
	Y = a * (0.17697 + 0.81240 + 0.01063) * G;
	Z = a * (0.00 + 0.01 + 0.99) * B;
	cout << "X = " << X << " Y = " << Y << " Z = " << Z << endl;
}

void CMYtoRGB(double *C, double *M, double *Y,double *R, double *G, double *B)
{
	*R = 1 - *C;
	*G = 1 - *M;
	*B = 1 - *Y;
}
void CMYtoCMYK(double *C, double *M, double *Y)
{
	double R = 0, G = 0, B = 0;
	CMYtoRGB( C, M,  Y, &R, &G, &B);
	RGBtoCMYK(R, G, B);

}
void CMYtoHSV(double *C, double *M, double *Y)
{
	double R = 0, G = 0, B = 0;
	CMYtoRGB(C, M, Y, &R, &G, &B);
	RGBtoHSV(R, G, B);
}
void CMYtoHSL(double *C, double *M, double *Y)
{
	double R = 0, G = 0, B = 0;
	CMYtoRGB(C, M, Y, &R, &G, &B);
	RGBtoHSL(R, G, B);
}
void CMYtoXYZ(double *C, double *M, double *Y)
{
	double R = 0, G = 0, B = 0;
	CMYtoRGB(C, M, Y, &R, &G, &B);
	RGBtoXYZ(R, G, B);
}

void CMYKtoRGB(double *C, double *M, double *Y,double *K, double *R, double *G, double *B)
{

	*R = (1 - *C) / (1 - *K);
	*G = (1 - *M) / (1 - *K);
	*B = (1 - *Y) / (1 - *K);
}

void CMYKtoCMY(double *C, double *M, double *Y,double*K)
{
	double R = 0, G = 0, B = 0;
	CMYKtoRGB(C, M, Y,K,&R, &G, &B);
	RGBtoCMY(R, G, B);

}
void CMYKtoHSV(double *C, double *M, double *Y, double*K)
{
	double R = 0, G = 0, B = 0;
	CMYKtoRGB(C, M, Y,K, &R, &G, &B);
	RGBtoHSV(R, G, B);
}
void CMYKtoHSL(double *C, double *M, double *Y, double*K)
{
	double R = 0, G = 0, B = 0;
	CMYKtoRGB(C, M, Y,K, &R, &G, &B);
	RGBtoHSL(R, G, B);
}
void CMYKtoXYZ(double *C, double *M, double *Y, double*K)
{
	double R = 0, G = 0, B = 0;
	CMYKtoRGB(C, M, Y,K, &R, &G, &B);
	RGBtoXYZ(R, G, B);
}

void HSVtoRGB(double *H, double *S, double *V, int *Hi, double *Vmin, double *Vinc, double *Vdec, double *a,double *R, double *G, double *B)
{
	*Hi = int(*H / 60) % 6;
	cout << *Hi << endl;
	*Vmin = *V * (100 - *S) / 100;
	*a = (*V - *Vmin)* (int(*H) % 60) / 60;
	*Vdec = *V  - *a;
	*Vinc = *Vmin + *a;
	if (*Hi == 0)
	{
		*R = *V/100;
		*G = *Vinc/100;
		*B = *Vmin/100;
	}
	if (*Hi == 1)
	{
		*R = *Vdec/100;
		*G = *V/100;
		*B = *Vmin/100;
	}
	if (*Hi == 2)
	{
		*R = *Vmin/100;
		*G = *V/100;
		*B = *Vinc/100;
		
	}
	if (*Hi == 3)
	{
		*R = *Vmin/100;
		*G = *Vdec/100;
		*B = *V/100;

	}
	if (*Hi == 4)
	{
		*R = *Vinc/100;
		*G = *Vmin/100;
		*B = *V/100;

	}
	if (*Hi == 5)
	{
		*R = *V/100;
		*G = *Vmin/100;
		*B = *Vdec/100;

	}
}

void HSVtoCMY(double *H, double *S, double *V)
{
	double R = 0, G = 0, B = 0, Vmin=0, Vinc = 0, Vdec=0, a=0;
	int Hi;
	HSVtoRGB(H, S, V, &Hi, &Vmin, &Vinc, &Vdec, &a, &R, &G, &B);
	RGBtoCMY(R, G, B);

}
void HSVtoCMYK(double *H, double *S, double *V)
{
	double R = 0, G = 0, B = 0, Vmin = 0, Vinc = 0, Vdec = 0, a = 0;
	int Hi;
	HSVtoRGB(H, S, V, &Hi, &Vmin, &Vinc, &Vdec, &a, &R, &G, &B);
	RGBtoCMYK(R, G, B);
}
void HSVtoHSL(double *H, double *S, double *V)
{
	double R = 0, G = 0, B = 0, Vmin = 0, Vinc = 0, Vdec = 0, a = 0;
	int Hi = 0;;
	HSVtoRGB(H, S, V, &Hi, &Vmin, &Vinc, &Vdec, &a, &R, &G, &B);
	RGBtoHSL(R, G, B);
}
void HSVtoXYZ(double *H, double *S, double *V)
{
	double R = 0, G = 0, B = 0, Vmin = 0, Vinc = 0, Vdec = 0, a = 0;
	int Hi;
	HSVtoRGB(H, S, V, &Hi, &Vmin, &Vinc, &Vdec, &a, &R, &G, &B);
	RGBtoXYZ(R, G, B);
}

void HSLtoRGB(double *H, double *S, double *L, double *R, double *G, double *B, double *Q, double *P, double *Tr, double *Tg, double *Tb)
{
	if (*L < 0.5)
		*Q = *L * (1.0 + *S);
	else if (*L >= 0.5)
		*Q = *L + *S - *L * *S;
	*P = 2.0 * *L - *Q;

	*Tr = *H / 360 + 0.3333;
	if (*Tr < 0)
		*Tr += 1.0;
	else if(*Tr > 1)
		*Tr -= 1.0;
	if (*Tr < 1 / 6)
		*R = *P + (*Q - *P) * 6.0 * *Tr;
	else if (*Tr >= 0.16666 && *Tr < 0.5)
		*R = *Q;
	else if (*Tr >= 0.5 && *Tr < 0.66666)
		*R = *P + (*Q - *P) * (0.66666 - *Tr) * 6.0;
	else
		*R = *P;


	*Tg = *H / 360 ;
	if (*Tg < 0)
		*Tg += 1.0;
	else if (*Tg > 1)
		*Tg -= 1.0;
	if (*Tg < 0.16666)
		*G = *P + (*Q - *P) * 6.0 * *Tg;
	else if (*Tg >= 0.16666 && *Tg < 0.5)
		*G = *Q;
	 else if (*Tg >= 0.5 && *Tg < 0.66666)
		*G = *P + (*Q - *P) * (0.66666 - *Tg) * 6.0;
	else
		*G = *P;

	*Tb = *H / 360 - 0.3333;
	if (*Tb < 0)
		*Tb += 1.0;
   else if (*Tb > 1)
		*Tb -= 1.0;
	if (*Tb < 0.16666)
		*B = *P + (*Q - *P) * 6.0 * *Tb;
	else if (*Tb >= 0.16666 && *Tb < 0.5)
		*B = *Q;
	else if (*Tb >= 0.5 && *Tb < 0.66666)
		*B = *P + (*Q - *P) * (0.66666 - *Tb) * 6.0;
	else
		*B = *P;
}

void HSLtoCMY(double *H, double *S, double *L)
{
	double R = 0, G = 0, B = 0, Q = 0, P = 0, Tr = 0, Tg = 0, Tb = 0;
	HSLtoRGB(H, S, L, &R, &G, &B, &Q, &P, &Tr, &Tg, &Tb);
	RGBtoCMY(R, G, B);

}
void HSLtoCMYK(double *H, double *S, double *L)
{
	double R = 0, G = 0, B = 0, Q = 0, P = 0, Tr = 0, Tg = 0, Tb = 0;
	HSLtoRGB(H, S, L, &R, &G, &B, &Q, &P, &Tr, &Tg, &Tb);
	RGBtoCMYK(R, G, B);
}
void HSLtoHSV(double *H, double *S, double *L)
{
	double R = 0, G = 0, B = 0, Q = 0, P = 0, Tr = 0, Tg = 0, Tb = 0;
	HSLtoRGB(H, S, L, &R, &G, &B, &Q, &P, &Tr, &Tg, &Tb);
	RGBtoHSL(R, G, B);
}
void HSLtoXYZ(double *H, double *S, double *L)
{
	double R = 0, G = 0, B = 0, Q = 0, P = 0, Tr = 0, Tg = 0, Tb = 0;

	HSLtoRGB(H, S, L, &R, &G, &B, &Q, &P, &Tr, &Tg, &Tb);
	RGBtoXYZ(R, G, B);
}

int main()
{
	double R =0 , G =0 , B=0, C, M, Y, K, H, S, V, L;
	double Vmin = 0, Vinc = 0, Vdec = 0, a = 0, Q = 0, P = 0, Tr = 0, Tg = 0, Tb = 0;
	int Hi = 0;
	string colormodel;
	int i, maxcolor = 255;
	cout << "What do u want convert? \n";
	cin >> colormodel;
	if (colormodel == "RGB") {
		cout << "Enter R, G, B\n";
		cin >> R;
		cin >> G;
		cin >> B;

		R = R / maxcolor;
		G = G / maxcolor;
		B = B / maxcolor;

		cout << "RGB to CMY\n";
		RGBtoCMY(R, G, B);

		cout << "RGB to CMYK\n";
		RGBtoCMYK(R, G, B);

		cout << "RGB to HSV\n";
		RGBtoHSV(R, G, B);

		cout << "RGB to HLS\n";
		RGBtoHSL(R, G, B);

		cout << "RGB to XYZ\n";
		RGBtoXYZ(R, G, B);
	}
	if (colormodel == "CMY") 
	{
		cout << "Enter C, M, Y\n";
		cin >> C;
		cin >> M;
		cin >> Y;
		
		cout << "CMY to RGB\n";
		CMYtoRGB(&C, &M, &Y,&R,&G,&B);
		cout << "R = " << R << " G = " << G << " B = " << B << endl;

		cout << "CMY to CMYK\n";
		CMYtoCMYK(&C, &M, &Y);

		cout << "CMY to HSV\n";
		CMYtoHSV(&C, &M, &Y);

		cout << "CMY to HSL\n";
		CMYtoHSL(&C, &M, &Y);

		cout << "CMY to XYZ\n";
		CMYtoXYZ(&C, &M, &Y);
	}
	if (colormodel == "CMYK")
	{
		cout << "Enter C, M, Y, K \n";
		cout << "K < C,M,Y\n";
		cin >> C;
		cin >> M;
		cin >> Y;
		cin >> K;
		
		cout << "CMYK to RGB\n";
		CMYKtoRGB(&C, &M, &Y, &K, &R, &G, &B);
		cout << "R = " << R << " G = " << G << " B = " << B << endl;
		
		cout << "CMYK to CMY\n";
		CMYKtoCMY(&C, &M, &Y,&K);

		cout << "CMYK to HSV\n";
		CMYKtoHSV(&C, &M, &Y,&K);

		cout << "CMYK to HSL\n";
		CMYKtoHSL(&C, &M, &Y,&K);

		cout << "CMYK to XYZ\n";
		CMYKtoXYZ(&C, &M, &Y,&K);
	}
	if (colormodel == "HSV")
	{
		cout << "Enter H, S, V\n";
		cin >> H;
		cin >> S;
		cin >> V;
		
		cout << "HSV to RGB\n";
		HSVtoRGB(&H, &S, &V,&Hi,&Vmin,&Vinc,&Vdec,&a,&R, &G, &B);
		cout << "R = " << R << " G = " << G << " B = " << B << endl;

		cout << "HSV to CMY\n";
		HSVtoCMY(&H, &S, &V);

		cout << "HSV to CMYK\n";
		HSVtoCMYK(&H, &S, &V);

		cout << "HSV to HSL\n";
		HSVtoHSL(&H, &S, &V);

		cout << "HSV to XYZ\n";
		HSVtoXYZ(&H, &S, &V);
	}
	if (colormodel == "HSL")
	{
		cout << "Enter H, S, L\n";
		cin >> H;
		cin >> S;
		cin >> L;

		cout << "HSL to RGB\n";
		HSLtoRGB(&H, &S, &L, &R, &G, &B, &Q, &P, &Tr,&Tg, &Tb);
		cout << "R = " << R << " G = " << G << " B = " << B << endl;

		cout << "HSL to CMY\n";
		HSLtoCMY(&H, &S, &L);

		cout << "HSL to CMYK\n";
		HSLtoCMYK(&H, &S, &L);

		cout << "HSL to HSV\n";
		HSLtoHSV(&H, &S, &L);

		cout << "HSL to XYZ\n";
		HSLtoXYZ(&H, &S, &L);

	}
	cin >> i; //чтобы программа не закрывалась
	return 0;
}