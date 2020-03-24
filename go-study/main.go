//refer https://geektutu.com/post/quick-golang.html
//https://draveness.me/golang-101

package main

import (
	"errors"
	"fmt"
	"os"
	"reflect"
)

func main() {
	fmt.Println("Hello World!")

	str1 := "Golang"
	str2 := "Go语言"
	fmt.Println(reflect.TypeOf(str2[2]).Kind()) // uint8
	fmt.Println(str1[2], string(str1[2]))       // 108 l
	fmt.Printf("%d %c\n", str2[2], str2[2])     // 232 è
	fmt.Println("len(str2)：", len(str2))        // len(str2)： 8

	runeArr := []rune(str2)
	fmt.Println(reflect.TypeOf(runeArr[2]).Kind()) // int32
	fmt.Println(runeArr[2], string(runeArr[2]))    // 35821 语
	fmt.Println("len(runeArr)：", len(runeArr))     // len(runeArr)： 4

	arr := [5]int{1, 2, 3, 4, 5}
	for i := 0; i < len(arr); i++ {
		arr[i] += 100
	}
	fmt.Println(arr) // [101 102 103 104 105]

	slice1 := make([]float32, 0)          // 长度为0的切片
	slice2 := make([]float32, 3, 5)       // [0 0 0] 长度为3容量为5的切片
	fmt.Println(len(slice1), cap(slice2)) // 3 5

	// 添加元素，切片容量可以根据需要自动扩展
	slice2 = append(slice2, 1, 2, 3, 4)   // [0, 0, 0, 1, 2, 3, 4]
	fmt.Println(len(slice2), cap(slice2)) // 7 12
	// 子切片 [start, end)
	sub1 := slice2[3:]  // [1 2 3 4]
	sub2 := slice2[:3]  // [0 0 0]
	sub3 := slice2[1:4] // [0 0 1]
	// 合并切片
	combined := append(sub1, sub2...) // [1, 2, 3, 4, 0, 0, 0]

	fmt.Print(sub3, combined)

	// 仅声明
	m1 := make(map[string]int)
	// 声明时初始化
	m2 := map[string]string{
		"Sam":   "Male",
		"Alice": "Female",
	}
	// 赋值/修改
	m1["Tom"] = 18

	fmt.Print(m2)

	str := "Golang"
	var p *string = &str // p 是指向 str 的指针
	*p = "Hello"
	fmt.Println(str) // Hello 修改了 p，str 的值也发生了改变

	num := 100
	add(num)
	fmt.Println(num) // 100，num 没有变化

	realAdd(&num)
	fmt.Println(num) // 101，指针传递，num 被修改

	age := 18
	if age < 18 {
		fmt.Printf("Kid")
	} else {
		fmt.Printf("Adult")
	}

	// 可以简写为：
	if age := 18; age < 18 {
		fmt.Printf("Kid")
	} else {
		fmt.Printf("Adult")
	}

	type Gender int8
	const (
		MALE   Gender = 1
		FEMALE Gender = 2
	)

	gender := MALE

	switch gender {
	case FEMALE:
		fmt.Println("female")
	case MALE:
		fmt.Println("male")
	default:
		fmt.Println("unknown")
	}
	// male

	switch gender {
	case FEMALE:
		fmt.Println("female")
		fallthrough
	case MALE:
		fmt.Println("male")
		fallthrough
	default:
		fmt.Println("unknown")
	}
	// 输出结果
	// male
	// unknown
	sum := 0
	for i := 0; i < 10; i++ {
		if sum > 50 {
			break
		}
		sum += i
	}

	nums := []int{10, 20, 30, 40}
	for i, num := range nums {
		fmt.Println(i, num)
	}
	// 0 20
	// 1 30
	// 2 40

	for key, value := range m2 {
		fmt.Println(key, value)
	}
	// Sam Male
	// Alice Female
	quo, rem := div(100, 17)
	fmt.Println(quo, rem)        // 5 15
	fmt.Println(sumnum(100, 17)) // 117

	if err := hello(""); err != nil {
		fmt.Println(err)
	}
}

func add(num int) {
	num++
}

func realAdd(num *int) {
	*num++
}

func sumnum(num1 int, num2 int) int {
	return num1 + num2
}

func sumnumans(num1 int, num2 int) (ans int) {
	ans = num1 + num2
	return
}

func div(num1 int, num2 int) (int, int) {
	return num1 / num2, num1 % num2
}

func readfile() {
	_, err := os.Open("filename.txt")
	if err != nil {
		fmt.Println(err)
	}
}

func hello(name string) error {
	if len(name) == 0 {
		return errors.New("error: name is null")
	}
	fmt.Println("Hello,", name)
	return nil
}
