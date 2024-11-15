#include<bits/stdc++.h>
using namespace std;

class SmartDevice{
protected:
    int deviceID;
    string brandName;
    double powerRating;
public:
    SmartDevice(int id, const string &brand, double power)
        : deviceID(id), brandName(brand), powerRating(power) {}

    virtual ~SmartDevice() {}

    double getPowerRating() const {
        return powerRating;
    }

    virtual void diagnose() const = 0; 

    
};

class ThermostatDevice : public SmartDevice {
private:
    double minTemp;
    double maxTemp;
    string mode;

public:
    ThermostatDevice(int id, const string &brand, double power, double minT, double maxT, const string &m)
        : SmartDevice(id, brand, power), minTemp(minT), maxTemp(maxT), mode(m) {}

    virtual double calculatePowerConsumption(double hours) const {
        return powerRating * hours;
    }

    void diagnose() const override {
        cout << "Thermostat Device Diagnostics: Mode - " << mode
             << ", Temperature Range: " << minTemp << "C to " << maxTemp << "C" << endl;
    }
};

class SecurityCameraDevice : public SmartDevice {
private:
    string resolution;
    double recordingHours; 

public:
    SecurityCameraDevice(int id, const string &brand, double power, const string &res, double recHours)
        : SmartDevice(id, brand, power), resolution(res), recordingHours(recHours) {}

    double calculateDataUsage(double days) const {
        return recordingHours * days * 1; 
    }

    void diagnose() const override {
        cout << "Security Camera Device Diagnostics: Resolution - " << resolution
             << ", Recording Hours: " << recordingHours << " hours/day" << endl;
    }
};

class SmartThermostat : public ThermostatDevice {
private:
    bool remoteControlEnabled;

public:
    SmartThermostat(int id, const string &brand, double power, double minT, double maxT, const string &m, bool remote)
        : ThermostatDevice(id, brand, power, minT, maxT, m), remoteControlEnabled(remote) {}

    double calculatePowerConsumption(double hours) const override {
        return ThermostatDevice::calculatePowerConsumption(hours) * (remoteControlEnabled ? 0.9 : 1.0);
    }

    void diagnose() const override {
        cout << "Smart Thermostat Diagnostics: Remote Control - "
             << (remoteControlEnabled ? "Enabled" : "Disabled") << endl;
    }
};

class HybridThermostat : public ThermostatDevice, public SecurityCameraDevice,public SmartDevice {
private:
    double energySavingEfficiency; 

public:
    HybridThermostat(int id, const string &brand, double power, double minT, double maxT, const string &m,
                     const string &res, double recHours, double efficiency)
        :SmartDevice(id,brand,power), ThermostatDevice(id, brand, power, minT, maxT, m),
          SecurityCameraDevice(id, brand, power, res, recHours), energySavingEfficiency(efficiency) {}

    double calculatePowerConsumption(double hours) const override {
        return ThermostatDevice::calculatePowerConsumption(hours) * (1 - energySavingEfficiency / 100);
    }

    double calculateDataUsage(double days) const {
        return SecurityCameraDevice::calculateDataUsage(days); 
    }

    void diagnose() const override {
        cout << "Hybrid Thermostat Diagnostics: Energy Saving Efficiency - " << energySavingEfficiency << "%" << endl;
    }

    
};

void sort_devices_by_power(vector<SmartDevice*>& devices) {
    sort(devices.begin(), devices.end(), [](SmartDevice* a, SmartDevice* b) {
        return a->getPowerRating() > b->getPowerRating();
    });
}

int main(){
    vector<SmartDevice*> devices;
    devices.push_back(new ThermostatDevice(1, "BrandA", 1500, 18, 30, "cooling"));
    devices.push_back(new SecurityCameraDevice(2, "BrandB", 500, "1080p", 12));
    devices.push_back(new SmartThermostat(3, "BrandC", 1200, 16, 28, "heating", true));
    //devices.push_back(new HybridThermostat(4, "BrandD", 1800, 15, 25, "cooling", "4K", 24, 20));

  
    sort_devices_by_power(devices);


    
    cout << "All Devices:\n";
    for (SmartDevice* device : devices) {
        device->diagnose();
        cout << endl;
    }

    cout << "Hybrid Thermostat Details:\n";
    for (SmartDevice* device : devices) {
        if (HybridThermostat* hybrid = dynamic_cast<HybridThermostat*>(device)) {
            hybrid->diagnose();
            cout << endl;
        }
    }

    for (SmartDevice* device : devices) {
        delete device;
    }

    return 0;
}