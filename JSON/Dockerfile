FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o myapp -lstdc++ -std=c++11 json_exercise_1.cpp
CMD ["./myapp"]