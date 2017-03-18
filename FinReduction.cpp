#include <iostream>
#include "Express.h"
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;


int main(int argc, char* argv[]) {
    cout << "*******配送成本对比*******" << endl;
//    cout << "输入参数格式：<发货省> <收货省> <包裹重量(kg)>" << endl;
    time_t start;
    start = time(NULL);

    //定义不同的快递公司对象
    Express yunda("韵达","/Users/lousiyuan/cainiao_work/fin_fee_reduction/kuaidi_price/yunda.txt");
    Express ems("EMS","/Users/lousiyuan/cainiao_work/fin_fee_reduction/kuaidi_price/ems.txt");
    Express baishi("百世","/Users/lousiyuan/cainiao_work/fin_fee_reduction/kuaidi_price/baishi.txt");
    Express debang("德邦","/Users/lousiyuan/cainiao_work/fin_fee_reduction/kuaidi_price/debang.txt");
    Express shentong("申通","/Users/lousiyuan/cainiao_work/fin_fee_reduction/kuaidi_price/shentong.txt");
    Express yuantong("圆通","/Users/lousiyuan/cainiao_work/fin_fee_reduction/kuaidi_price/yuantong.txt");
    Express zhongtong("中通","/Users/lousiyuan/cainiao_work/fin_fee_reduction/kuaidi_price/zhongtong.txt");

    vector<Express> expressVec;
    expressVec.push_back(yunda);
    expressVec.push_back(ems);
    expressVec.push_back(baishi);
    expressVec.push_back(debang);
    expressVec.push_back(shentong);
    expressVec.push_back(yuantong);
    expressVec.push_back(zhongtong);


//    cout << "*******test*******" << endl;
//    yunda.printInfo();
//    ems.printInfo();
//    baishi.printInfo();
//    debang.printInfo();
//    shentong.printInfo();
//    yuantong.printInfo();
//    zhongtong.printInfo();
//    cout << "******************" << endl;

    //思路: 1. 读取线路参数 2. 计算每家快递公司的费用 3.写入结果文件
    ofstream outputFile;
    outputFile.open("/Users/lousiyuan/cainiao_work/fin_fee_reduction/output_result.txt",ios::out);

    //读取实际线路
    string inputLineFile = "/Users/lousiyuan/cainiao_work/fin_fee_reduction/real_kuaidi_order.txt";
    ifstream infile(inputLineFile);
    string lbx, mailno, sendProv, recProv, cpCode;
    double weight;
    while(infile >> lbx >> mailno >> sendProv >> recProv >> weight >> cpCode){
        double ceilWeight = ceil(weight);
        string bestChoiseName;
        double bestChoiseFee = 10000.0;
        for(vector<Express>::iterator it = expressVec.begin(); it != expressVec.end(); ++it){
            Express e = *it;
            map< pair<string, string>, pair<double,double> > priceCombination = e.priceCombination;
            map< pair<string, string>, pair<double,double> >::iterator iter = priceCombination.find(make_pair(sendProv,recProv));
            if( iter != priceCombination.end()){
                double firstWeightPrice = iter->second.first;
                double secondWeightPrice = iter->second.second;
                double curFee = firstWeightPrice + (ceilWeight-1)*secondWeightPrice;
                if(curFee <= bestChoiseFee){
                    bestChoiseName = e.objectName;
                    bestChoiseFee = curFee;
                }

//                cout << e.objectName << "的收费为：" << curFee << "（元）" << endl;
            }
        }
        //写入结果文件
        if(outputFile.is_open()){
            outputFile << lbx << " " << mailno << " " << bestChoiseFee << " " << bestChoiseName << endl;
        }else{
            cout << "output_result.txt 写入失败" << endl;
        }
    }

    outputFile.close();

    cout << "所有步骤计算完成! " << " 共计耗时: " << time(NULL)-start << endl;

    return 0;
}