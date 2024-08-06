## Possible errors and how resolve them.


### std::chrono error
The problem was with ```libstd++6.dll```. It was solved by using the argument ```-static-libstdc++``` in g++. MinGW was taking libstd++6.dll from Windows instead of the one in MinGW.