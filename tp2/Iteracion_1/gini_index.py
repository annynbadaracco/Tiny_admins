import requests
import ctypes

country = input("Enter ISO country code: ")



api_url = f"https://api.worldbank.org/v2/en/country/{country}/indicator/SI.POV.GINI?format=json&date=2011:2020&per_page=32500&page=1"

response = requests.get(api_url)

data = response.json()

for entry in data[1]:
    print(entry["date"], entry["value"])

print("\n----------------------\n")

print("Converted list: \n")

library = ctypes.CDLL('./conversion.so')

library.conversion.argtypes = (ctypes.c_float,)

library.conversion.restype = ctypes.c_int

def conversion(num):
    return library.conversion(num)


for entry in data[1]:
    year = entry["date"]
    gini = entry["value"]

    if gini is not None:
        converted = conversion(gini)
        print(year, converted)
    else:
        print(year, "None")