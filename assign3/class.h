class MyClass {
    public:
        MyClass();
        MyClass(int data);
        ~MyClass();
        void setData(int data);
        int getData() const;
    private:
        int data;
        bool validData(int data) const;
};
