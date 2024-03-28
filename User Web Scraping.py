import csv
import requests
from bs4 import BeautifulSoup
# pip install requests beautifulsoup4


def scrape_product_info(url):
    # Send a GET request to the URL
    response = requests.get(url)
    
    # Check if the request was successful
    if response.status_code == 200:
        # Parse the HTML content of the page
        soup = BeautifulSoup(response.text, 'html.parser')
        
        # Find all product elements
        products = soup.find_all('div', class_='zg_itemImmersion')
        
        # Initialize a list to store product information
        product_info = []
        
        for product in products:
            # Extract product name
            name = product.find('div', class_='p13n-sc-truncate').text.strip()
            
            # Extract product price
            price = product.find('span', class_='p13n-sc-price').text.strip()
            
            # Extract product rating
            rating = product.find('span', class_='a-icon-alt').text.strip()
            
            # Append product information to the list
            product_info.append([name, price, rating])
        
        return product_info
    else:
        print("Failed to retrieve data from the URL.")
        return None

def save_to_csv(product_info, filename):
    # Write product information to a CSV file
    with open(filename, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Name', 'Price', 'Rating'])
        writer.writerows(product_info)
    print(f"Data saved to {filename}")

if __name__ == "__main__":
    # URL of the Best Sellers page for electronics on Amazon
    url = "https://www.amazon.com/Best-Sellers-Electronics/zgbs/electronics/"
    
    # Scrape product information
    product_info = scrape_product_info(url)
    
    if product_info:
        # Save product information to a CSV file
        save_to_csv(product_info, 'amazon_electronics_best_sellers.csv')
