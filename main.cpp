#include <iostream>
#include <string>
using namespace std;

string decToBin(int num) 
{
    string bin = "";
	if (num == 0) return "0";
    while (num > 0) 
    {
        int bit = num % 2;
        bin = char(bit + '0') + bin;
        num /= 2;
    }
    return bin;
}

string decToHex(int num) 
{
    string hex = "";
    char hexChars[] = "0123456789ABCDEF";
	if (num == 0) return "0";
    while (num > 0) 
    {
        int rem = num % 16;
        hex = hexChars[rem] + hex;
        num /= 16;
    }
    return hex;
}

int binToDec(string bin) 
{
    int dec = 0;

    for (int i = 0; i < bin.size(); i++) 
    {
        dec = dec * 2 + (bin[i] - '0'); // shift left and add current bit
    }
    return dec;
}

int hexToDec(string hex) 
{
    int dec = 0;

    for (int i = 0; i < hex.size(); i++) 
    {
        char c = toupper(hex[i]);
        int val;
        if (c >= '0' && c <= '9')
        {
            val = c - '0';
        }
        else
        {
            val = 10 + (c - 'A');
        }
        dec = dec * 16 + val;
    }
    return dec;
}

int stringToInt(string s) 
{
    int result = 0;
    bool neg = false;
    int i = 0;
    if (s[0] == '-') 
    {
        neg = true;
        i = 1;
    }
    for (; i < s.size(); i++) {
        result = result * 10 + (s[i] - '0');
    }
    return neg ? -result : result;
}


float stringToFloat(string s) 
{
    float result = 0;
    bool neg = false;
    int i = 0;

    if (s[0] == '-') 
    {
        neg = true;
        i = 1;
    }

    // int part
    for (; i < s.size() && s[i] != '.'; i++) 
    {
        result = result * 10 + (s[i] - '0');
    }

    // frac part
    if (i < s.size() && s[i] == '.') 
    {
        i++;
        float frac = 0;
        float divisor = 1;

        for (; i < s.size(); i++) 
        {
            frac = frac * 10 + (s[i] - '0');
            divisor *= 10;
        }
        result += frac / divisor;
    }

    return neg ? -result : result;
}

string floatToBin(float num) 
{
    int intPart = (int)num;
    float fracPart = num - intPart;

    string bin = decToBin(intPart);
    bin += ".";

    int count = 0;
    while (fracPart > 0 && count < 10) 
    {
        fracPart *= 2;
        if (fracPart >= 1) 
        {
            bin += "1";
            fracPart -= 1;
        }
        else 
        {
            bin += "0";
        }
        ++count;
    }
    return bin;
}

int main() {
    while (true)
    {
        string fromType, toType;
        string input;
        cout << "Enter the type you are inputting\n";
        cout << "-DEC\n";
        cout << "-HEX\n";
        cout << "-Float\n";
        cout << "-BIN\n";
        cout << "-STOP\n";
        cin >> fromType;

        cout << "Enter the type you want to convert to\n";
        cout << "-DEC\n";
        cout << "-HEX\n";
        cout << "-Float\n";
        cout << "-BIN\n";
        cout << "-STOP\n";;
        cin >> toType;

        cout << "Enter the number: ";
        cin >> input;
        

        for (auto& c : fromType) c = toupper(c);
        for (auto& c : toType) c = toupper(c);

        float decValue = 0;

        if (fromType == "DEC") {
            decValue = stringToInt(input);
        }
        else if (fromType == "BIN") {
            decValue = binToDec(input);
        }
        else if (fromType == "HEX") {
            decValue = hexToDec(input);
        }
        else if (fromType == "FLOAT") {
            decValue = stringToFloat(input);
        }
        else {
            cout << "Invalid input type!" << endl;
            return 1;
        }
        if (toType == "STOP" || fromType == "STOP" || toType == "stop" || fromType == "stop") 
        {
            break;
		}

        // Step 2: Convert decimal to target type
        if (toType == "DEC") {
            cout << "Converted number: " << (int)decValue << endl;
        }
        else if (toType == "BIN") {
            if (fromType == "FLOAT") {
                cout << "Converted number: " << floatToBin(decValue) << endl;
            }
            else {
                cout << "Converted number: " << decToBin((int)decValue) << endl;
            }
        }
        else if (toType == "HEX") {
            cout << "Converted number: " << decToHex((int)decValue) << endl;
        }
        else if (toType == "FLOAT") {
            if (fromType == "FLOAT") {
                cout << "Already a float, invalid conversion." << endl;
            }
            else {
                cout << "Converted number: " << decValue << endl;
            }
        }
        else {
            cout << "Invalid conversion type!" << endl;
        }
		cout << endl;
    }
    return 0;
}
