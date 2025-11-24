// Subject: 도서관 책 정렬 알고리즘. 

// 개발 동기: 과거 도서부에서 활동한 경험이 있었고, 
//		그때 당시에 도서를 배치하는데 고생한 기억이 있었기에 
//		이를 더욱 빠르고 간편하게 처리할 방안을 생각하고자 개발하게 되었다. 

// 1. 청구기호 (총류-철학-종교-사회과학-자연-기술과학-예술-언어-문학-역사) 
// 2. 저자기호 (ㄱ-ㄴ-ㄷ-ㄹ-ㅁ-ㅂ-ㅅ-ㅇ-ㅈ-ㅊ-ㅋ-ㅌ-ㅍ-ㅎ)
// 3. 도서기호 (ㄱ-ㄴ-ㄷ-ㄹ-ㅁ-ㅂ-ㅅ-ㅇ-ㅈ-ㅊ-ㅋ-ㅌ-ㅍ-ㅎ)

//	알고리즘
//		선택정렬: 배열에서 가장 작은(또는 가장 큰) 요소를 찾아 
//			정렬되지 않은 부분의 가장 앞 요소와 교환하는 과정을 반복하는 정렬 알고리즘


#include<stdio.h>
#include <string.h>

struct Book
{
	unsigned short genre;	// 분야, 청구기호
	char writer[50];		// 저자, 저자기호
	char title[50];			// 제목, 도서기호
};

// 선택 정렬을 통해 책을 순서대로 배치한다. 
void selection_sort(struct Book books[], int n)
{
	int i, j;
    for (i=0;i<n-1;i++) {
        int minIndex = i;

        for (j=i+1;j<n;j++) {

            // 1) genre값 우선 비교
            if (books[j].genre < books[minIndex].genre) {
                minIndex = j;
            }
            // 2) genre의 값이 같으면 writer를 비교
            else if (books[j].genre == books[minIndex].genre &&
                    strcmp(books[j].writer, books[minIndex].writer) < 0) {
                minIndex = j;
            }
            // 3) genre, writer 모두 같으면 title값 비교
            else if (books[j].genre == books[minIndex].genre &&
                    strcmp(books[j].writer, books[minIndex].writer) == 0 &&
                    strcmp(books[j].title, books[minIndex].title) < 0) {
                minIndex = j;
            }
        }

        // swap
        if (minIndex != i) {
            struct Book temp = books[i];
            books[i] = books[minIndex];
            books[minIndex] = temp;
        }
    }
}


int main(void)
{
    struct Book books[50];
    
    
	unsigned char n;
    printf("정렬할 책의 수: ");
	scanf("%hhu", &n);
    
    unsigned char i = 0;
	
	for(i=0;i<n;i++){
		// 청구기호 입력. 
        printf("\n책 분야\n");		
        printf("0. 총류\n");
        printf("1. 철학\n");
        printf("2. 종교\n");
        printf("3. 사회과학\n");
        printf("4. 자연과학\n");
        printf("5. 기술과학\n");
        printf("6. 예술\n");
        printf("7. 언어\n");
        printf("8. 문학\n");
        printf("9. 역사\n");
        printf("답: ");
        scanf("%hu", &books[i].genre);
        
        // 저자기호 입력. 
        printf("\n저자: ");
        scanf("%s", books[i].writer);

		// 도서기호 입력. 
        printf("\n제목: ");
        scanf("%s", books[i].title);
	}

    selection_sort(books, n);

    printf("\n 정렬된 도서 목록 \n");
    for (i=0;i<n;i++) {
        printf("[%d] 청구기호: %hu이상 %s - %s\n",
               i + 1,
               books[i].genre*100,
               books[i].writer,
               books[i].title);
    }

    return 0;
}



