#include <iostream> 
#include <fstream> 
#include <ctime>
using namespace std; 

//Сравнение двух строк
int string_compare(char *str1, char *str2) { 
    int i = 0; 
    while (str1[i] != '\0' && str2[i] != '\0') { 
        if (str1[i] != str2[i]) return 0; 
        i++; } 
    return str1[i] == str2[i]; 
} 
class Product{ 
    char name[31]; 
    double price; 
    int day, month, year; 
    public: 
    //Конструктор по умолчанию
    Product() : price(0), day(0), month(0), year(0) { 
        name[0] = '\0';} 
     //Конструктор с параметрами
    Product(char n[], double p, int d, int m, int y) : price(p), day(d), month(m), year(y) { 
        int i = 0; 
        while (n[i] != '\0' && i < 30) { 
            name[i] = n[i]; 
            i++;} 
        name[i] = '\0';} 
  
    //Конструктор копирования
    Product(const Product &temp_ob) { 
        for (int i = 0; i < 31; i++) { 
            this->name[i] = temp_ob.name[i];} 
        this->price = temp_ob.price; 
        this->day = temp_ob.day; 
        this->month = temp_ob.month; 
        this->year = temp_ob.year; 
    } 
 
    //Оператор присваивания
    Product &operator=(const Product &temp_ob) { 
        //Проверкасамокопирования
        if (this == &temp_ob) return *this; 
        for (int i = 0; i < 31; i++) { 
            this->name[i] = temp_ob.name[i]; } 
        this->price = temp_ob.price; 
        this->day = temp_ob.day; 
        this->month = temp_ob.month; 
        this->year = temp_ob.year; 
        return *this; 
    } 
 
    char* get_name() { 
        return name;}
	double get_price() { 
        return price;}
    int get_day() { 
        return day;}
    int get_month() { 
        return month;}
    int get_year() { 
        return year;} 
	void show() { 
        cout<<name<<" "<<price<<" "<<day<<"/"<<month<<"/"<<year<< endl;}

    int is_expired() {
        time_t now = time(0);
        tm *date = localtime(&now);
        int current_day = date->tm_mday;
        int current_month = date->tm_mon + 1;
        int current_year = date->tm_year + 1900;
        if (get_year() < current_year) return 1;
        if (get_year() == current_year && get_month() < current_month) return 1;
        if (get_year() == current_year && get_month() == current_month && get_day() < current_day) return 1;
        return 0;}

};
 
class Store{ 
    char name[31], city[21];
    int count; 
    Product *products; 
    unsigned int *amount; 
 
    public: 
    //Пустой магазин
    Store() : count(0), products(nullptr), amount(nullptr) { 
        name[0] = '\0'; 
        city[0] = '\0';} 
 
    //Создаём магазин
    Store(int n) : count(n) { 
        products = new(nothrow) Product[count]; 
        amount = new(nothrow) unsigned int[count]; 
        if (products == nullptr || amount == nullptr) { // check
	        delete[] products;
	        delete[] amount;
	        products = nullptr;
	        amount = nullptr;
	        count = 0;
	        return;}
        name[0] = '\0'; 
        city[0] = '\0'; 
        for (int i = 0; i < count; i++) { 
            amount[i] = 0;} 
    } 

    //Записываем название магазина и города 
    void set_name(char n[]) { 
        int i = 0; 
        while (n[i] != '\0' && i < 30) { 
            name[i] = n[i]; 
            i++;} 
        name[i] = '\0';} 
 
    void set_city(char c[]) { 
        int i = 0; 
        while (c[i] != '\0' && i < 20) { 
            city[i] = c[i]; 
            i++;} 
        city[i] = '\0';} 
 
    //Записываем товар и количество его экземпляров в i
    void set_product(Product p, unsigned int a, int i) { 
        products[i] = p; 
        amount[i] = a;} 
 
 //Увеличиваем количество товара
    void add_amount(int i, unsigned int a) {
        amount[i] += a;}

//Устанавливаем число уникальных товаров
    void set_product_count(int n) {
        count = n;}
    
    //Конструктор копировани
    Store(const Store &temp_ob) { 
        this->count = temp_ob.count; 
        for (int i = 0; i < 31; i++) { 
            this->name[i] = temp_ob.name[i];} 
        for (int i = 0; i < 21; i++) { 
            this->city[i] = temp_ob.city[i];} 

        this->products = new(nothrow) Product[this->count]; 
        this->amount = new(nothrow) unsigned int[this->count]; 
       if (this->products == nullptr || this->amount == nullptr) {
        delete[] this->products;
        delete[] this->amount;
		this->products = nullptr;
        this->amount = nullptr;
        this->count = 0;
        return;}
        
        for (int i = 0; i < this->count; i++) { 
            this->products[i] = temp_ob.products[i]; 
            this->amount[i] = temp_ob.amount[i];}   
    } 
    //Оператор =
    Store &operator=(const Store &temp_ob) {
    if (this == &temp_ob) return *this;

    Product *new_products = new(nothrow) Product[temp_ob.count];
    unsigned int *new_amount = new(nothrow) unsigned int[temp_ob.count];

    if (new_products == nullptr || new_amount == nullptr) {
        delete[] new_products;
        delete[] new_amount;
        return *this;}

    for (int i = 0; i < temp_ob.count; i++) {
        new_products[i] = temp_ob.products[i];
        new_amount[i] = temp_ob.amount[i];}

    delete[] products;
    delete[] amount;
	products = new_products;
    amount = new_amount;
    count = temp_ob.count;
	for (int i = 0; i < 31; i++) {
        name[i] = temp_ob.name[i];}
	for (int i = 0; i < 21; i++) {
        city[i] = temp_ob.city[i];}

    return *this;
} 

    void show() { 
        cout<<name<<" "<<city<<" "<<count;
        for (int i = 0; i < count; i++) {
            cout<<" "<<products[i].get_name()<<" "<<amount[i];}
        cout<<endl;} 
     
    int get_product_count() {
        return count;}
   Product* get_products() { 
		return products;} 
	char* get_city() { 
		return city;} 
	 char* get_name() { 
		return name;} 
	unsigned int get_amount(int i) {
		return amount[i];}
 
	~Store() { 
        delete[] products; 
        delete[] amount;} 
}; 
 
int main() { 
    char name[31]; 
    int n, day, month, year;
    double price;

    char store_name[31], store_city[21], store_product_name[31]; ;
    unsigned int store_count, store_products_count, store_product_amount; 

    int control; //Код запроса для свитч
    char city_input[21], product_input[31], store_input[31]; 
 
    //Открываем файл с товарами
    ifstream fprod("products.txt"); 
    if (!(fprod.is_open())){ 
        cout<<"error"<<endl; 
        return 1;} 
 
    //Открываем файл с магазинами
    ifstream fstores("stores.txt"); 
    if (!(fstores.is_open())){ 
        cout<<"error"<<endl; 
        return 2;} 
     
    //Считываем количество товаров 
    fprod>>n; 
    if (n < 0) {
        cout<<"Error5"<<endl;
        return 5;}
    
 
    //Создаём динамический массив всех товаров
    Product *products = new(nothrow) Product[n]; 
    if (products == nullptr) { 
        cout<<"Memory error"<<endl; 
        return 3;} 
 
    // Читаем каждый товар и записываем их в массиве
    for (int i = 0; i < n; i++){ 
        fprod>>name>>price>>day>>month>>year; 
        products[i] = Product(name, price, day, month, year);} 
  
    fprod.close(); 
 
    //Читаем количество магазинов
    int file_count;
    fstores>>file_count;//сколько магазинов записано в файле
    if (file_count < 0) {
        cout<<"Error6"<<endl;
        return 6;}
    store_count = 0;//здесь считаем успешно добавленные магазины
                  
	Store *stores = new(nothrow) Store[file_count];
    if (stores == nullptr) {
        cout<<"Memory error"<<endl;
        delete[] products;
        return 4;}

	//названия всех магазинов из файла включая не добавленные
    char (*seen_names)[31] = new(nothrow) char[file_count][31];
    if (seen_names == nullptr) {
        cout<<"Memory error"<<endl;
        delete[] products;
        delete[] stores;
        return 4;}
    int seen_count = 0;   //сколько названий уже записано

//Читаем данные магазинов и их товарные позиции
    for (int i = 0; i < file_count; i++) {
	    fstores>>store_name>>store_city>>store_products_count;
	    //Проверяем встречалось ли название магазина среди уже добавленных
        int flag = 0;
        for (int j = 0; j < seen_count; j++) {
            if (string_compare(store_name, seen_names[j])) {
                flag = 1;
                break;}
        }
	    if (flag == 1) {
	    	cout<<"Store with "<<store_name<<" name already exists."<<endl;
	    	//Строки товаров повторного магазина всё равно читаем, но не сохраняем
	    	for (unsigned int j = 0; j < store_products_count; j++) {
	    		fstores>>store_product_name>>store_product_amount;}
	    	continue;}
	    //запоминаем название даже если магазин потом не будет добавлен
        for (int c = 0; c < 31; c++) {
            seen_names[seen_count][c] = store_name[c];}
        seen_count++;

    //Собираем магазин в свободной позиции store_count
    stores[store_count] = Store(store_products_count);
    stores[store_count].set_name(store_name);
    stores[store_count].set_city(store_city);
    int actual_products = 0;   //число уникальных товаров
    int valid_store = 1;       //0 если хотя бы одного товара нет в products.txt

	    for (unsigned int j = 0; j < store_products_count; j++) {
	    	fstores>>store_product_name>>store_product_amount;
	    	//Ищем товар в общем массиве products
	    	int found_product = -1;
	    	for (int k = 0; k < n; k++) {
	    		if (string_compare(products[k].get_name(), store_product_name)) {
	    			found_product = k;
	    			break;}
	  }
	    	if (found_product == -1) {
	    		cout<<"Product "<<store_product_name<<" not exists."<< endl;
	    		valid_store = 0;
	    		continue;}   //строку дочитали остальные товары всё равно обработаем

	    	//Если такой товар уже есть прибавляем количество
	    	int found = 0;
	    	for (int k = 0; k < actual_products; k++) {
	    		if (string_compare(store_product_name, stores[store_count].get_products()[k].get_name())) {
	    			stores[store_count].add_amount(k, store_product_amount);
	    			found = 1;
	    			break;}
	  }
	    	//Если товар встретился впервые добавляем новую позицию
	    	if (found == 0) {
	    		stores[store_count].set_product(products[found_product], store_product_amount, actual_products);
	    		actual_products++;}
	 }

	    if (valid_store == 1) {
	    	stores[store_count].set_product_count(actual_products);
	    	store_count++;}   //магазин добавлен 
	    	else {
	    	cout<<"Store "<<store_name<<" not added."<<endl;}
    }
 
    //Читаем код запроса
    while (1) {
        cin>>control; 
        switch (control) { 
            case 0:
                //Завершение программы
                fstores.close();
	    	    delete[] products;
	    	    delete[] stores;
	    	    delete[] seen_names;
	    	    return 0;
	case 1:{
		//Вывод информации обо всех товарах
		for (int i = 0; i < n; i++) { 
			products[i].show(); 
		} 
		break;}
	case 2:{
		//Вывод информации обо всех магазинах
		 for (unsigned int i = 0; i < store_count; i++) { 
			stores[i].show();}  
		break;}
	case 3:{
		//Запрос названия магазина
		cin>>store_input; 
		int found = 0;
		for (unsigned int i = 0; i < store_count; i++) { 
			if (string_compare(store_input, stores[i].get_name())) { 
				found = 1;
				double sum = 0;
				for (int j = 0; j < stores[i].get_product_count(); j++) {
					if (!(stores[i].get_products()[j].is_expired())) {                
						sum += stores[i].get_products()[j].get_price() * stores[i].get_amount(j);}
				}
			cout<<"Price of all products from this store: "<<sum<<endl;} 
		} 
		if (!found) cout<<"Store not found"<<endl;
		break;}
	case 4:{
		//Запрос товара и города
		cin>>product_input>>city_input; 
		unsigned int total = 0;
		for (unsigned int i = 0; i < store_count; i++) {
			if (string_compare(city_input, stores[i].get_city())) {
				for (int j = 0; j < stores[i].get_product_count();j++) {
					if (string_compare(product_input, stores[i].get_products()[j].get_name()) && !(stores[i].get_products()[j].is_expired())) {
						total += stores[i].get_amount(j);}
				}
			}
		}
		cout<<total<<endl;
		break;}

	case 5:{
		//Поиск магазина с наибольшим количеством экземпляров
		cin>>product_input;
		unsigned int max_amount = 0;
		int flag = -1;
	for (unsigned int i = 0; i < store_count; i++) {
			unsigned int total = 0;
			for (int j = 0; j < stores[i].get_product_count(); j++) {
				if (string_compare(product_input, stores[i].get_products()[j].get_name())) {
					if (!(stores[i].get_products()[j].is_expired())) {
						total += stores[i].get_amount(j);}
				}    
			}
			if (total > 0 && (flag == -1 || total > max_amount)) {  //chtobi ne vivodit tam gde net tovara
				max_amount = total;
				flag = i;}
		}
		if (flag != -1) {
			stores[flag].show();
			cout<< "amount: "<<max_amount<<endl;} 
			else {
			cout<<"no stores"<<endl;}
		break;}

	default:{
		cout<<"This function doesn`t exist"<<endl;
		break;}
	}
}
 
    fstores.close(); 
    delete[] products; 
    delete[] stores; 
    delete[] seen_names;
    return 0; 
}

