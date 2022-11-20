#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <stdexcept>
#include <mutex>

namespace Bankaccount {

    class Bankaccount {
        
        private:

            int balanceValue = 0; //assume balance is in the smallest allowable unit, i.e. US cents to avoid double precision nonsense
            bool isActive = false;
            std::mutex mutex;

        public:

            Bankaccount() = default;

            void open() {

                const std::lock_guard lock(mutex);

                if (isActive){
                    throw std::runtime_error("Account is already opened.");
                } 

                balanceValue = 0;
                isActive = true;
                
            }

            void close() {

                const std::lock_guard lock(mutex);

                if (!isActive){
                    throw std::runtime_error("Account is already closed.");
                } 

                balanceValue = 0;
                isActive = false;

            }

            int balance(){

                if (isActive){
                    return balanceValue;
                } else {
                    throw std::runtime_error("Account is not active.");
                }

            }

            void deposit(int depositValue){

                const std::lock_guard lock(mutex);

                if (!isActive){
                    throw std::runtime_error("Cannot deposit to closed account.");                    
                }

                if (depositValue <= 0){
                    throw std::runtime_error("Cannot deposit negative or zero value.");
                }

                balanceValue += depositValue;

            }

            void withdraw(int withdrawValue){

                const std::lock_guard lock(mutex);

                if (!isActive){
                    throw std::runtime_error("Cannot withdraw from a closed account.");                    
                }

                if (withdrawValue < 0 ){
                    throw std::runtime_error("Cannot withdraw negative value.");
                }

                if (balanceValue - withdrawValue < 0){
                    throw std::runtime_error("Cannot withdraw an amount that will result in negative balance.");
                }

                balanceValue -= withdrawValue;

            }

    };  // class Bankaccount



}  // namespace Bankaccount

#endif  // BANK_ACCOUNT_H