/**
 *  @file    main.cpp
 *  @author  Nader Nabil,
 *  @date    10/5/2016
 *
 *  @brief Problem was proposed by Alexandra Mirzac
 *
 *  @section DESCRIPTION
 *
 *  Probability of event in random arrays
 *  --------------------------------------
 *
 *  The Problem:
 *  We have a set from {0, 1, 2, …….N} from which where are extracting randomly numbers,
 *  until we have a number consisting of 5 different digits.
 *  Store the number of successful extractions in a separate variable.
 *  Compute the probability of extracting the digit “1” the most of times.
 *
 *  P (probability of an event) = Number of succesful experiments / Number of total experiments;
 *  M (medium value) = Summ of [(Number of succesful experiments) * P(probability of an event)]
 */


#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector
#include <set>
#include <time.h>

using namespace std;

void generate_experiment();
void count_probability();

bool myfunction (int i, int j) {
  return (i==j);
}

// golble variables
const int range = 10;

int N, NoE, NLF, NSE, LFE, NoD, NoEM, SoDA_2;
int SoDA;
int64_t NoSE;
size_t NoDEA;
float P, P2;
double M;


int arr[range];

int main () {

    /*
     * ************** Edited ***************
     * NoE = Number of Total experiments     (user input)
     * NSE = Number Of Successful experiments (the experiments we found NLF in) (only the code is computing this part)
     * NLF = Number we Looking for            (user input for example: '1')
     * NoSE = Number of Successful Extractions we need (  the program is computing this )
     * NoD = size of distinct array we are looking for
     * NoEM = number of expermints that meet our condition
     * SoDA = Sum every element in every distinct array
     * SoDA_ = Sum every element in a single distinct array
     * NoDEA = Number of distinct elemtns in the array
     * P (probability of an event)= Number of succesful experiments / Number of total experiments;
     * M (medium value) = Summ of [(Number of succesful experiments) * P (probability of an event)]
     */

    // initlizing the variables
    NoE = 0;
    NLF = 0;
    NSE = 0;
    NoSE = 0;
    LFE = 0;
    NoD = 5;
    M = 0;
    SoDA=0;
    SoDA_2 = 0;
    NoDEA = 0;

    srand ((unsigned)time (NULL));

    cout << "Enter number of experiments: ";
    cin >> NoE;

    cout << "Enter the number we are looking for: ";
    cin >> NLF;

    cout << "Number of discrete integer: ";
    cin >> NoD;

    for(int k = 0; k < NoE; k++) {
        generate_experiment();
    }


    // calculating M
    M = (float)NoDEA /(float)NoE;

    count_probability();

    return 0;
}

void generate_experiment() {

    cout << "New experimnt...\n";

    int Max = rand() % range + 1;
    cout << "Array Max Number: " << Max << endl;

    cout << "Elements Array: ";
    for (int i = 0; i < Max; i++)
    {
        arr[i] = rand() % Max + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    // count how many number we found NLF
    std::vector<int> myvector (arr, arr+10);
    int64_t NLF_count = std::count (arr, arr+range, range);

    NLF_count = std::count (myvector.begin(), myvector.end(), NLF);
    std::cout << NLF << " appears " << NLF_count  << " times.\n";

    // remove the repeated elements and then return distinct elements
    set<int> distinct_elements(arr, arr + range);

    // to print and count the distinct array

    // this for old compier, use auto it in for()
    set<int>::iterator it;

    cout << "Distinct Elements: ";
    for ( it = distinct_elements.begin(); it != distinct_elements.end(); ++it )
    {
        std::cout << " " << *it;
        SoDA_2 += *it;
        SoDA += *it;
    }
    cout << endl;

    //
    NoDEA += distinct_elements.size();

    // the total number of the distinct elements
    cout << "Number of Distinct Array: " << distinct_elements.size() << endl;

    // the sum of numbers in the distinct elements
    cout << "Sum of Number in Distinct Array: " << SoDA_2 << endl << endl;

    if(distinct_elements.size() == NoD)
    {
        // count of all experiments taht meet our condition
        NoEM++;
        if(NLF_count != 0) {
            NSE++;
            NoSE += NLF_count; // number of total extractions
            // this is test
            P = (float)NSE / (float)NoE; //P = (probability of an event)= Number of succesful experiments / Number of total experiments;
        }
    }

    SoDA_2 = 0; // clear the SoDA_2 for the next expermint SoDA count all experiments
}

void count_probability() {

    cout << endl << "--- Calculating Probability ---" << endl;

#ifdef DEBUG
    // comment those if you like to clear the sereen
    cout << "Count of all experiments that meet our case: " << NoEM << endl;
    cout << "Sum of Succesful experiments (how many time we found '" << NLF << "'): " << NoSE << endl;
    cout << "Number of successfull experiments: " << NSE << endl;
    cout << "Sum of all the elements in all distinct arrays: "<< SoDA << endl;
    cout << "Sum of count of distinct elements in arrays: "<< NoDEA << endl;
#endif

    cout << "Result of P: " << P << endl;
    cout << "Result of M: " << M << endl;
}
