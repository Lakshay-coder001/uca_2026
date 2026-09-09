function NewPromise(executorFunction) {
    let state = "pending";
    let value;
    let handlers = [];

    function resolve(result) {
        if (state !== "pending") return;

        state = "fulfilled";
        value = result;

        handlers.forEach(handle => handle());
    }

    function reject(error) {
        if (state !== "pending") return;

        state = "rejected";
        value = error;

        handlers.forEach(handle => handle());
    }

    this.then = function (onFulfilled) {
        return new NewPromise((resolveNext, rejectNext) => {

            function handle() {
                if (state === "fulfilled") {
                    try {
                        const result = onFulfilled(value);
                        resolveNext(result);
                    } catch (error) {
                        rejectNext(error);
                    }
                }
                else if (state === "rejected") {
                    rejectNext(value);
                }
            }

            if (state === "pending") {
                handlers.push(handle);
            } else {
                handle();
            }
        });
    };

    this.catch = function (onRejected) {
        return new NewPromise((resolveNext, rejectNext) => {

            function handle() {
                if (state === "rejected") {
                    try {
                        const result = onRejected(value);
                        resolveNext(result);
                    } catch (error) {
                        rejectNext(error);
                    }
                }
                else if (state === "fulfilled") {
                    resolveNext(value);
                }
            }

            if (state === "pending") {
                handlers.push(handle);
            } else {
                handle();
            }
        });
    };
    try {
        executorFunction(resolve, reject);
    } catch (error) {
        reject(error);
    }
}

const p = new NewPromise((resolve,reject) =>{
    resolve(5); 
})
.then(value => {
    return value * 2;
})
.then(value => {
    return value * 5;
})
.then(value => {
    console.log("value: ",value);
    return value/50;
})
.then(value => {
    console.log("Value: ",value)
});

// p.then(value => {
//     console.log("Value:", value);
// }); // this will give undefined as it is not chained with the promise